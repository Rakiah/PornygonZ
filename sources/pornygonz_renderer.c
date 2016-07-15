/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_renderer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 12:25:13 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

static int		calculate_vertex_size(void)
{
	int		vertex_size;

	vertex_size = sizeof(float) * 3;
	if (g_core.attribs & PORNYGONZ_COLOR)
		vertex_size += sizeof(float) * 4;
	if (g_core.attribs & PORNYGONZ_TEXTURE_COORDS)
		vertex_size += sizeof(float) * 2;
	return (vertex_size);
}

static t_vertex	generate_vertex(void *data, int offset, int vertex_size)
{
	t_vertex	vert;
	int			pos;
	int			float_offset;

	pos = offset * vertex_size;
	vert.pos = process_vertex_shader(data + pos);
	float_offset = sizeof(float) * 3;
	if (g_core.attribs & PORNYGONZ_COLOR)
	{
		vert.color = *((t_vector4f *)(data + pos + float_offset));
		float_offset += sizeof(float) * 4;
	}
	if (g_core.attribs & PORNYGONZ_TEXTURE_COORDS)
		vert.tex_coords = *((t_vector2f *)(data + pos + float_offset));
	return (vert);
}

void			pornygonz_draw_arrays(t_draw_type type, int first, int count)
{
	int			i;
	int			vert_size;
	t_vertex	vertices[count];
	t_buffer	*data;

	(void)type;
	vert_size = calculate_vertex_size();
	data = ((t_internal_core *)g_core.data)->vertex_bind.buffer;
	i = first - 1;
	while (++i < count)
		vertices[i - first] = generate_vertex(data->b, i, vert_size);
	draw_verts_as_triangles(vertices, count);
}

static int		calculate_index_size(t_element_type type)
{
	int index_size;

	index_size = sizeof(unsigned int);
	if (type == PORNYGONZ_UNSIGNED_SHORT || type == PORNYGONZ_SHORT)
		index_size = sizeof(unsigned short);
	else if (type == PORNYGONZ_UNSIGNED_INT || type == PORNYGONZ_INT)
		index_size = sizeof(unsigned int);
	else if (type == PORNYGONZ_UNSIGNED_LONG || type == PORNYGONZ_LONG)
		index_size = sizeof(unsigned long);
	return (index_size);
}

void			pornygonz_draw_elements(t_draw_type draw_type,
								t_element_type indices_type,
								int first, int count)
{
	int			i;
	int			vert_size;
	int			index_size;
	t_buffer	*data[2];
	t_vertex	vertices[count];

	(void)draw_type;
	index_size = calculate_index_size(indices_type);
	vert_size = calculate_vertex_size();
	data[0] = ((t_internal_core *)g_core.data)->vertex_bind.buffer;
	data[1] = ((t_internal_core *)g_core.data)->index_bind.buffer;
	i = first - 1;
	while (++i < count)
		vertices[i - first] = generate_vertex(data[0]->b, *((int *)(data[1]->b +
											(i * index_size))), vert_size);
	draw_verts_as_triangles(vertices, count);
}
