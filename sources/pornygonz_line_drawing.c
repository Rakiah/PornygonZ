/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_line_drawing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:03:37 by bkabbas           #+#    #+#             */
/*   Updated: 2016/07/15 13:12:01 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

static void	tex_draw_pixel(SDL_Surface *s, int x, int y, int pixel)
{
	*((unsigned int *)(s->pixels + ((y * s->pitch) +
						(x * s->format->BytesPerPixel)))) = pixel;
}

void		generate_fragment(float *fragment, float *values)
{
	int	i;

	i = 0;
	if (g_core.attribs & PORNYGONZ_DEPTH_BUFFER)
	{
		fragment[i] = values[i];
		i++;
	}
	if (g_core.attribs & PORNYGONZ_COLOR)
	{
		fragment[i + 0] = minf(values[i + 0], 1.0f);
		fragment[i + 1] = minf(values[i + 1], 1.0f);
		fragment[i + 2] = minf(values[i + 2], 1.0f);
		fragment[i + 3] = minf(values[i + 3], 1.0f);
		i += 4;
	}
	if (g_core.attribs & PORNYGONZ_TEXTURE_COORDS)
	{
		fragment[i + 0] = clampf01(minf(values[i + 0], 1.0f) / values[i + 2]);
		fragment[i + 1] = clampf01(minf(values[i + 1], 1.0f) / values[i + 2]);
	}
}

void		draw_scan_line_inner(float *value, int pos[2])
{
	int				pixel;
	float			fragment[13];
	t_internal_core	*core;

	fragment[0] = pos[0];
	fragment[1] = pos[1];
	core = (t_internal_core *)g_core.data;
	generate_fragment(fragment + 2, value);
	if (g_core.attribs & PORNYGONZ_DEPTH_BUFFER)
	{
		if (fragment[2] >= core->depth_buffer[pos[0]][pos[1]])
			return ;
		else
			core->depth_buffer[pos[0]][pos[1]] = fragment[2];
	}
	pixel = v4f_to_color(process_fragment_shader(fragment));
	tex_draw_pixel((SDL_Surface *)g_core.surface, pos[0], pos[1], pixel);
}

void		draw_scan_line(t_line *lines[2], t_list *ipls, int y)
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
		draw_scan_line_inner(value, pos);
		pos[0]++;
		i = -1;
		while (++i < (int)ipls->count)
			value[i] += step[i];
	}
}

void		draw_between_line(t_line *lines[2], t_list *ipls, t_bool swap)
{
	t_line	*tmp;
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
