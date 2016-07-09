/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_uniforms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/07 01:25:37 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

t_uniform	*pornygonz_find_uniform(char *name)
{
	t_list		*uniforms;
	t_uniform	*iterator;

	uniforms = ((t_internal_core *)g_core.data)->uniforms;
	list_set_start(uniforms);
	while ((iterator = list_next(uniforms)) != NULL)
		if (rstd_strcmp(name, iterator->name) == 0)
			return (iterator);
	return (NULL);
}

void		pornygonz_add_uniform(char *name, void *data, size_t size)
{
	t_uniform *uniform;

	uniform = pornygonz_find_uniform(name);
	if (uniform == NULL)
	{
		uniform = malloc(sizeof(t_uniform));
		uniform->name = rstd_strdup(name);
		list_push_back(((t_internal_core *)g_core.data)->uniforms, uniform);
	}
	uniform->data = data;
	uniform->size = size;
}

void		*pornygonz_get_uniform(char *name, size_t *size)
{
	t_uniform *uniform;

	uniform = pornygonz_find_uniform(name);
	if (uniform == NULL)
		return (NULL);
	*size = uniform->size;
	return (uniform->data);
}
