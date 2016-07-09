/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/07 00:26:46 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz_internal.h"

t_vertex	*vertex_new(t_vector4f pos,
						t_vector4f color,
						t_vector2f tex_coords)
{
	t_vertex *vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	vertex->pos = pos;
	vertex->color = color;
	vertex->tex_coords = tex_coords;
	return (vertex);
}

t_vertex	*vertex_new_init(void)
{
	t_vertex *vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	vertex->pos = V4F_ZERO;
	vertex->color = V4F_ZERO;
	vertex->tex_coords = V2F_ZERO;
	return (vertex);
}

t_vertex	*vertex_new_cpy(t_vertex *src)
{
	return (vertex_new(src->pos, src->color, src->tex_coords));
}

t_bool		vertex_inside_frustum(t_vertex *v)
{
	return ((fabs(v->pos.x) <= fabs(v->pos.w)) &&
			(fabs(v->pos.y) <= fabs(v->pos.w)) &&
			(fabs(v->pos.z) <= fabs(v->pos.w)));
}
