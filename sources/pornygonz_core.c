/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 23:11:24 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

static t_internal_core	*internal_core_init(void)
{
	t_internal_core *core;

	core = malloc(sizeof(t_internal_core));
	core->vertex_buffers = list_new();
	core->index_buffers = list_new();
	core->texture_buffers = list_new();
	core->uniforms = list_new();
	core->vertex_bind.buffer = NULL;
	core->index_bind.buffer = NULL;
	core->texture_bind.buffer = NULL;
	core->vertex_bind.buffer = 0;
	core->index_bind.buffer = 0;
	core->texture_bind.buffer = 0;
	core->vs = &vertex_shader_default;
	core->fs = &fragment_shader_default;
	return (core);
}

void					buffer_delete(t_buffer *buf)
{
	free(buf->b);
	free(buf);
}

void					uniform_delete(t_uniform *uniform)
{
	free(uniform->name);
	free(uniform);
}

static void				internal_core_destroy(void)
{
	t_internal_core *data;

	data = g_core.data;
	list_delete_inner(data->vertex_buffers, (void (*)(void *))buffer_delete);
	list_delete_inner(data->index_buffers, (void (*)(void *))buffer_delete);
	list_delete_inner(data->texture_buffers, (void (*)(void *))buffer_delete);
	list_delete_inner(data->uniforms, (void (*)(void *))uniform_delete);
	free(data);
}

void					buffer_add_data(t_buffer *buf, void *d, size_t s)
{
	void *tmp;

	if (buf == NULL)
		return ;
	tmp = rstd_memjoin(buf->b, d, buf->size, s);
	free(buf->b);
	buf->b = tmp;
	buf->size += s;
}

int						pornygonz_init(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (0);
	g_core.init = NULL;
	g_core.window = NULL;
	g_core.surface = NULL;
	g_core.data = internal_core_init();
	g_core.attribs = 0;
	g_core.width = 0;
	g_core.height = 0;
	return (1);
}

void					pornygonz_quit(void)
{
	pornygonz_destroy_window();
	internal_core_destroy();
	SDL_Quit();
}
