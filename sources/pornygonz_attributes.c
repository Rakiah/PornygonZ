/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_attributes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:15:57 by bkabbas           #+#    #+#             */
/*   Updated: 2016/07/15 13:16:12 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

void			pornygonz_enable_vertex_attribute(int attribute)
{
	g_core.attribs |= attribute;
}

void			pornygonz_disable_vertex_attribute(int attribute)
{
	g_core.attribs &= ~(attribute);
}
