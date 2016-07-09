/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_fragment_shaders.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 18:58:09 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

t_vector4f	process_fragment_shader(void *vert)
{
	float out[4];

	rstd_memset(out, 0, sizeof(out));
	((t_internal_core *)g_core.data)->fs(vert, out);
	return (V4F_INIT(out[1], out[2], out[3], out[0]));
}

void		pornygonz_bind_fragment_shader(t_fs_callback shader)
{
	((t_internal_core *)g_core.data)->fs = shader;
}

void		fragment_shader_default(const float *in_vertex, float out[4])
{
	(void)in_vertex;
	out[0] = 1.0f;
	out[1] = 1.0f;
	out[2] = 1.0f;
	out[3] = 1.0f;
}
