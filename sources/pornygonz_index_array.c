/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_index_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 23:17:07 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

unsigned int	pornygonz_create_index_array(void)
{
	t_list *indices;

	indices = ((t_internal_core *)g_core.data)->index_buffers;
	list_push_back(indices, rstd_memalloc(sizeof(t_buffer)));
	return (indices->count);
}

void			pornygonz_delete_index_array(unsigned int id)
{
	t_list *indices;
	t_internal_core		*core;

	core = ((t_internal_core *)g_core.data);
	indices = core->index_buffers;
	list_remove_inner(indices, id - 1, list_default_remove_functor);
	if (core->index_bind.bind_index == id)
		pornygonz_bind_index_array(0);
}

void			pornygonz_bind_index_array(unsigned int id)
{
	t_internal_core *core;

	core = (t_internal_core *)g_core.data;
	core->index_bind.bind_index = id;
	core->index_bind.buffer = list_get_data_at(core->index_buffers, id - 1);
}

void			pornygonz_add_index_data(void *array, size_t array_size)
{
	t_buffer	*buffer;

	buffer = ((t_internal_core *)g_core.data)->index_bind.buffer;
	buffer_add_data(buffer, array, array_size);
}
