/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_clipper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 12:22:31 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz_clipper.h"

t_list		*clip_triangle(t_vertex *v1, t_vertex *v2, t_vertex *v3)
{
	t_list		*remapped;
	t_list		*temporary;

	remapped = list_new();
	temporary = list_new();
	list_push_back(remapped, vertex_new_cpy(v1));
	list_push_back(remapped, vertex_new_cpy(v2));
	list_push_back(remapped, vertex_new_cpy(v3));
	if (!clip_axis(remapped, temporary, 0) ||
		!clip_axis(remapped, temporary, 1) ||
		!clip_axis(remapped, temporary, 2))
	{
		free(temporary);
		free(remapped);
		return (NULL);
	}
	free(temporary);
	return (remapped);
}

t_bool		clip_axis(t_list *vertices, t_list *tmp, int index)
{
	clip_polygon_index(vertices, tmp, index, 1.0f);
	list_clear_inner(vertices, list_default_remove_functor);
	if (tmp->count == 0)
		return (FALSE);
	clip_polygon_index(tmp, vertices, index, -1.0f);
	list_clear_inner(tmp, list_default_remove_functor);
	if (vertices->count == 0)
		return (FALSE);
	return (TRUE);
}

t_vertex	*generate_lerped_vertex(t_vertex *v1, t_vertex *v2,
									float c1, float c2)
{
	t_vector4f	pos;
	t_vector4f	color;
	t_vector2f	tex_coords;
	float		lerp;

	lerp = (v1->pos.w - c1) / ((v1->pos.w - c1) - (v2->pos.w - c2));
	pos = v4f_lerp(v1->pos, v2->pos, lerp);
	if (g_core.attribs & PORNYGONZ_COLOR)
		color = v4f_lerp(v1->color, v2->color, lerp);
	else
		color = V4F_ZERO;
	if (g_core.attribs & PORNYGONZ_TEXTURE_COORDS)
		tex_coords = v2f_lerp(v1->tex_coords, v2->tex_coords, lerp);
	else
		tex_coords = V2F_ZERO;
	return (vertex_new(pos, color, tex_coords));
}

void		clip_polygon_index(t_list *vertices, t_list *result,
								int index, float side)
{
	t_vertex	*verts[2];
	float		component[2];
	t_bool		inside[2];

	verts[0] = vertices->end->data;
	component[0] = ((float *)(&verts[0]->pos))[index] * side;
	inside[0] = component[0] <= verts[0]->pos.w;
	while ((verts[1] = list_next(vertices)) != NULL)
	{
		component[1] = verts[1]->pos.v[index] * side;
		inside[1] = component[1] <= verts[1]->pos.w;
		if (inside[1] ^ inside[0])
			list_push_back(result,
					generate_lerped_vertex(verts[0], verts[1],
										component[0], component[1]));
		if (inside[1])
			list_push_back(result, vertex_new_cpy(verts[1]));
		verts[0] = verts[1];
		component[0] = component[1];
		inside[0] = inside[1];
	}
}
