/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_vertex_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 23:17:01 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

unsigned int	pornygonz_create_vertex_array(void)
{
	t_list *vertices;

	vertices = ((t_internal_core *)g_core.data)->vertex_buffers;
	list_push_back(vertices, rstd_memalloc(sizeof(t_buffer)));
	return (vertices->count);
}

void			pornygonz_delete_vertex_array(unsigned int id)
{
	t_list *vertices;
	t_internal_core		*core;

	core = ((t_internal_core *)g_core.data);
	vertices = core->vertex_buffers;
	list_remove_inner(vertices, id - 1, list_default_remove_functor);
	if (core->vertex_bind.bind_index == id)
		pornygonz_bind_vertex_array(0);
}

void			pornygonz_bind_vertex_array(unsigned int id)
{
	t_internal_core *core;

	core = (t_internal_core *)g_core.data;
	core->vertex_bind.bind_index = id;
	core->vertex_bind.buffer = list_get_data_at(core->vertex_buffers, id - 1);
}

void			pornygonz_add_vertex_data(void *array, size_t array_size)
{
	t_buffer *buffer;
	
	buffer = ((t_internal_core *)g_core.data)->vertex_bind.buffer;
	buffer_add_data(buffer, array, array_size);
}

void			pornygonz_enable_vertex_attribute(int attribute)
{
	g_core.attribs |= attribute;
}

void			pornygonz_disable_vertex_attribute(int attribute)
{
	g_core.attribs &= ~(attribute);
}
