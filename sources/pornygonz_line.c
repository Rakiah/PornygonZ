/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 13:07:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

void	line_setup(t_line *l, t_vertex *pts[2], t_list *ipls, int min_index)
{
	t_interpolant	*iterator;
	int				i;

	l->y_start = (int)pts[0]->pos.y;
	l->y_end = (int)pts[1]->pos.y;
	l->x_curr = pts[0]->pos.x;
	l->x_step = (float)(pts[1]->pos.x - pts[0]->pos.x) /
			(pts[1]->pos.y - pts[0]->pos.y);
	l->ipls_curr = malloc(sizeof(float) * ipls->count);
	l->ipls_step = malloc(sizeof(float) * ipls->count);
	i = 0;
	list_set_start(ipls);
	while ((iterator = list_next(ipls)) != NULL)
	{
		l->ipls_curr[i] = iterator->values[min_index];
		l->ipls_step[i] = iterator->y_step + iterator->x_step * l->x_step;
		i++;
	}
}

void	line_delete(t_line *l)
{
	free(l->ipls_curr);
	free(l->ipls_step);
}

void	line_do_step(t_line *l, int ipls_count)
{
	int i;

	i = -1;
	while (++i < ipls_count)
		l->ipls_curr[i] += l->ipls_step[i];
	l->x_curr += l->x_step;
}
