/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_rasterizer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 22:09:35 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

void		process_polygon(t_vertex *v1, t_vertex *v2, t_vertex *v3)
{
	t_list		*clipped_triangle;
	t_bool		visible[3];
	int			i;

	visible[0] = vertex_inside_frustum(v1);
	visible[1] = vertex_inside_frustum(v2);
	visible[2] = vertex_inside_frustum(v3);
	if (visible[0] && visible[1] && visible[2])
	{
		process_triangle(*v1, *v2, *v3);
		return ;
	}
	clipped_triangle = clip_triangle(v1, v2, v3);
	if (clipped_triangle == NULL || clipped_triangle->count == 0)
		return ;
	v1 = clipped_triangle->start->data;
	i = 1;
	while (i < (int)clipped_triangle->count - 1)
	{
		v2 = list_get_data_at(clipped_triangle, i);
		v3 = list_get_data_at(clipped_triangle, i + 1);
		process_triangle(*v1, *v2, *v3);
		i++;
	}
	list_delete_inner(clipped_triangle, list_default_remove_functor);
}

void		process_triangle(t_vertex v1, t_vertex v2, t_vertex v3)
{
	v1.pos = screen_coordinates_convert(v1.pos);
	v2.pos = screen_coordinates_convert(v2.pos);
	v3.pos = screen_coordinates_convert(v3.pos);
	draw_triangle((t_vertex *[]) { &v1, &v2, &v3 });
}

void		draw_triangle(t_vertex *verts[3])
{
	int			i;
	t_vertex	*swap;

	if (calculate_triangle_side(&verts[0]->pos, &verts[2]->pos, &verts[1]->pos))
		return ;
	i = 0;
	while (i < 2)
	{
		if (verts[i]->pos.y > verts[i + 1]->pos.y)
		{
			swap = verts[i];
			verts[i] = verts[i + 1];
			verts[i + 1] = swap;
			i = -1;
		}
		i++;
	}
	triangle_to_lines(verts);
}

t_list		*generate_interpolants(int attribs, t_vertex *v[3])
{
	t_list		*interpolants;

	interpolants = list_new();
	if (attribs & PORNYGONZ_DEPTH_BUFFER)
		list_push_back(interpolants, ipl_depth_buffer(v));
	if (attribs & PORNYGONZ_COLOR)
	{
		list_push_back(interpolants, ipl_color(v, 0));
		list_push_back(interpolants, ipl_color(v, 1));
		list_push_back(interpolants, ipl_color(v, 2));
		list_push_back(interpolants, ipl_color(v, 3));
	}
	if (attribs & PORNYGONZ_TEXTURE_COORDS)
	{
		list_push_back(interpolants, ipl_texture_coords(v, 0));
		list_push_back(interpolants, ipl_texture_coords(v, 1));
		list_push_back(interpolants, ipl_texture_perspective(v));
	}
	return (interpolants);
}

void		triangle_to_lines(t_vertex *verts[3])
{
	t_bool			side;
	t_line			lines[3];
	t_list			*ipls;

	ipls = generate_interpolants(g_core.attribs, verts);
	side = calculate_triangle_side(&verts[0]->pos, &verts[2]->pos, &verts[1]->pos);
	line_setup(&lines[0], (t_vertex *[]) { verts[0], verts[2] }, ipls, 0);
	line_setup(&lines[1], (t_vertex *[]) { verts[0], verts[1] }, ipls, 0);
	line_setup(&lines[2], (t_vertex *[]) { verts[1], verts[2] }, ipls, 1);
	draw_between_line((t_line *[]) { &lines[0], &lines[1] }, ipls, side);
	draw_between_line((t_line *[]) { &lines[0], &lines[2] }, ipls, side);
	line_delete(&lines[0]);
	line_delete(&lines[1]);
	line_delete(&lines[2]);
	list_delete_inner(ipls, list_default_remove_functor);
}

t_bool		calculate_triangle_side(t_vector4f *a, t_vector4f *b, t_vector4f *c)
{
	return (((b->x - a->x) * (c->y - a->y) -
			(c->x - a->x) * (b->y - a->y)) >= 0 ? 1 : 0);
}
