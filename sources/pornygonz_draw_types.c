/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_draw_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/06 16:24:55 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;


void	draw_verts_as_triangles(t_vertex *vertices, int size)
{
	int i;

	i = 0;
	while (i <= size - 3)
	{
		process_polygon(vertices + i, vertices + i + 1, vertices + i + 2);
		i += 3;
	}
}

void	draw_verts_as_lines(t_vertex *vertices, int size)
{

	(void)vertices;
	(void)size;
}
