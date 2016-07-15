/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_vertex_shaders.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 13:10:47 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

t_vector4f	process_vertex_shader(void *vert)
{
	t_vector4f	pos;
	float		out[4];

	rstd_memset(out, 0, sizeof(out));
	((t_internal_core *)g_core.data)->vs(vert, out);
	pos = V4F_INIT(out[0], out[1], out[2], out[3]);
	return (pos);
}

void		pornygonz_bind_vertex_shader(t_vs_callback shader)
{
	((t_internal_core *)g_core.data)->vs = shader;
}

void		vertex_shader_default(const float *in_vertex, float out[4])
{
	out[0] = in_vertex[0];
	out[1] = in_vertex[1];
	out[2] = in_vertex[2];
	out[3] = 1.0f;
}
