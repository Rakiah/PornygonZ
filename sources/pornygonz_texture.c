/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 12:24:06 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

unsigned int	pornygonz_create_texture(int w, int h, int bpp)
{
	t_list		*textures;
	t_buffer	*tex;

	tex = rstd_memalloc(sizeof(t_buffer));
	buffer_add_data(tex, (int[4]) { w, h, bpp * h, bpp }, sizeof(int) * 4);
	textures = ((t_internal_core *)g_core.data)->texture_buffers;
	list_push_back(textures, tex);
	return (textures->count);
}

void			pornygonz_delete_texture(unsigned int id)
{
	t_list				*textures;
	t_internal_core		*core;

	core = ((t_internal_core *)g_core.data);
	textures = core->texture_buffers;
	list_remove_inner(textures, id - 1, list_default_remove_functor);
	if (core->texture_bind.bind_index == id)
		pornygonz_bind_texture(0);
}

void			pornygonz_bind_texture(unsigned int id)
{
	t_internal_core *core;

	core = (t_internal_core *)g_core.data;
	core->texture_bind.bind_index = id;
	core->texture_bind.buffer = list_get_data_at(core->texture_buffers, id - 1);
}

void			pornygonz_add_texture_data(void *array, size_t array_size)
{
	t_buffer *buffer;

	buffer = ((t_internal_core *)g_core.data)->texture_bind.buffer;
	buffer_add_data(buffer, array, array_size);
}

void			pornygonz_get_texture_pixel(float u, float v, float out[4])
{
	int				size[4];
	int				offset;
	int				x;
	int				y;
	unsigned char	*pixels;

	if (((t_internal_core *)g_core.data)->texture_bind.buffer == NULL)
		return ;
	pixels = ((t_internal_core *)g_core.data)->texture_bind.buffer->b;
	rstd_memcpy(size, pixels, sizeof(size));
	pixels += sizeof(int) * 4;
	x = u * (size[0] - 1);
	y = v * (size[1] - 1);
	offset = y * size[2] + x * size[3];
	out[0] = *((unsigned char *)(pixels + offset + 3)) / 255.0f;
	out[1] = *((unsigned char *)(pixels + offset + 2)) / 255.0f;
	out[2] = *((unsigned char *)(pixels + offset + 1)) / 255.0f;
	out[3] = *((unsigned char *)(pixels + offset + 0)) / 255.0f;
}
