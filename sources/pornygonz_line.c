/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 22:09:06 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

static void	tex_draw_pixel(SDL_Surface *s, int x, int y, int pixel)
{
	*((unsigned int *)(s->pixels + ((y * s->pitch) + (x * s->format->BytesPerPixel)))) = pixel;
}

void	generate_fragment(float fragment[12], float *values, int value_size)
{
	int	i;

	i = -1;
	while (++i < value_size)
		fragment[i + 2] = minf(values[i], 1.0f);
}

void	draw_scan_line_inner(float *value, int value_size, int pos[2])
{
	int				pixel;
	float			fragment[13];
	t_internal_core	*core;

	fragment[0] = pos[0];
	fragment[1] = pos[1];
	core = (t_internal_core *)g_core.data;
	generate_fragment(fragment, value, value_size);
	if (g_core.attribs & PORNYGONZ_DEPTH_BUFFER &&
		fragment[2] >= core->depth_buffer[pos[0]][pos[1]])
		return ;
	if (g_core.attribs & PORNYGONZ_TEXTURE_COORDS)
	{
		fragment[3] = clampf01(fragment[3] * (1.0f / fragment[5]));
		fragment[4] = clampf01(fragment[4] * (1.0f / fragment[5]));
	}
	core->depth_buffer[pos[0]][pos[1]] = fragment[2];
	pixel = v4f_to_color(process_fragment_shader(fragment));
	tex_draw_pixel((SDL_Surface *)g_core.surface, pos[0], pos[1], pixel);
}

void	draw_scan_line(t_line *lines[2], t_list *ipls, int y)
{
	t_interpolant	*iterator;
	float			value[ipls->count];
	float			step[ipls->count];
	int				pos[2];
	int				i;

	i = 0;
	list_set_start(ipls);
	while ((iterator = list_next(ipls)))
	{
		value[i] = lines[0]->ipls_curr[i];
		step[i] = iterator->x_step;
		i++;
	}
	pos[0] = (int)lines[0]->x_curr;
	pos[1] = y;
	while (pos[0] < (int)lines[1]->x_curr)
	{
		draw_scan_line_inner(value, ipls->count, pos);
		pos[0]++;
		i = -1;
		while (++i < (int)ipls->count)
			value[i] += step[i];
	}
}

void	draw_between_line(t_line *lines[2], t_list *ipls, t_bool swap)
{
	t_line		*tmp;
	int		y_start;
	int		y_end;

	y_start = lines[1]->y_start;
	y_end = lines[1]->y_end;
	if (swap)
	{
		tmp = lines[0];
		lines[0] = lines[1];
		lines[1] = tmp;
	}
	while (y_start < y_end)
	{
		draw_scan_line(lines, ipls, y_start++);
		line_do_step(lines[0], ipls->count);
		line_do_step(lines[1], ipls->count);
	}

}

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
