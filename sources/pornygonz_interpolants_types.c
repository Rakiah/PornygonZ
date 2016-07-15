/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_interpolants_types.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 12:23:25 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_interpolant	*ipl_depth_buffer(t_vertex *v[3])
{
	t_vector4f	*pos[3];

	pos[0] = &v[0]->pos;
	pos[1] = &v[1]->pos;
	pos[2] = &v[2]->pos;
	return (ipl_new(pos, v[0]->pos.z, v[1]->pos.z, v[2]->pos.z));
}

t_interpolant	*ipl_color(t_vertex *v[3], int component_index)
{
	t_vector4f	*pos[3];

	pos[0] = &v[0]->pos;
	pos[1] = &v[1]->pos;
	pos[2] = &v[2]->pos;
	return (ipl_new(pos, ((float *)&v[0]->color)[component_index],
						((float *)&v[1]->color)[component_index],
						((float *)&v[2]->color)[component_index]));
}

t_interpolant	*ipl_texture_coords(t_vertex *v[3], int component_index)
{
	float		val[3];
	t_vector4f	*pos[3];

	pos[0] = &v[0]->pos;
	pos[1] = &v[1]->pos;
	pos[2] = &v[2]->pos;
	val[0] = (((float *)&v[0]->tex_coords)[component_index] / pos[0]->w);
	val[1] = (((float *)&v[1]->tex_coords)[component_index] / pos[1]->w);
	val[2] = (((float *)&v[2]->tex_coords)[component_index] / pos[2]->w);
	return (ipl_new(pos, val[0], val[1], val[2]));
}

t_interpolant	*ipl_texture_perspective(t_vertex *v[3])
{
	t_vector4f	*pos[3];

	pos[0] = &v[0]->pos;
	pos[1] = &v[1]->pos;
	pos[2] = &v[2]->pos;
	return (ipl_new(pos, 1.0f / pos[0]->w, 1.0f / pos[1]->w, 1.0f / pos[2]->w));
}
