/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:12:46 by bkabbas           #+#    #+#             */
/*   Updated: 2016/07/15 13:18:39 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

t_vector4f	screen_coordinates_convert(t_vector4f vector)
{
	t_internal_core		*internal;

	internal = (t_internal_core *)g_core.data;
	vector = m4f_mul_vector(&internal->screen_matrix, vector);
	vector.x /= vector.w;
	vector.y /= vector.w;
	vector.z /= vector.w;
	return (vector);
}

void		buffer_add_data(t_buffer *buf, void *d, size_t s)
{
	void *tmp;

	if (buf == NULL)
		return ;
	tmp = rstd_memjoin(buf->b, d, buf->size, s);
	free(buf->b);
	buf->b = tmp;
	buf->size += s;
}

void		buffer_delete(t_buffer *buf)
{
	free(buf->b);
	free(buf);
}

void		uniform_delete(t_uniform *uniform)
{
	free(uniform->name);
	free(uniform);
}
