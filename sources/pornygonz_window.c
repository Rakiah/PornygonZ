/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 20:58:28 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz.h"
#include "pornygonz_internal.h"

t_pornygonz_core	g_core;

int		pornygonz_create_window(int w, int h)
{
	SDL_Window *win;
	SDL_Surface *surface;
	t_internal_core *core;

	core = (t_internal_core *)g_core.data;
	if ((win = SDL_CreateWindow("pornygonz",
								SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								w, h, SDL_WINDOW_SHOWN)) == NULL)
		return (0);
	if ((surface = SDL_CreateRGBSurface(0, w, h,
										32, 0, 0, 0, 0)) == NULL)
		return (0);
	g_core.surface = (void *)surface;
	g_core.window = (void *)win;
	g_core.width = w;
	g_core.height = h;
	m4f_screen_space(&core->screen_matrix, w, h);
	core->depth_buffer = (float **)rstd_create_tab(w, h, sizeof(float));
	return (1);
}

void	pornygonz_destroy_window(void)
{
	SDL_FreeSurface(g_core.surface);
	SDL_DestroyWindow(g_core.window);
	g_core.width = 0;
	g_core.height = 0;
}

void	pornygonz_clear(void)
{
	int		i;
	int		j;
	t_internal_core	*internal;
	SDL_Surface	*surface;

	internal = (t_internal_core *)g_core.data;
	surface = (SDL_Surface *)g_core.surface;
	rstd_memset(surface->pixels, 0, surface->h * surface->pitch);
	i = 0;
	while (i < g_core.width)
	{
		j = 0;
		while (j < g_core.height)
		{
			internal->depth_buffer[i][j] = 9999999.0f;
			j++;
		}
		i++;
	}
}

void	pornygonz_swap_buffer(void)
{
	SDL_BlitSurface((SDL_Surface *)g_core.surface, NULL,
					SDL_GetWindowSurface(g_core.window), NULL);
	SDL_UpdateWindowSurface((SDL_Window *)g_core.window);
}

void	*pornygonz_get_window(void)
{
	return (g_core.window);
}

t_vector4f	screen_coordinates_convert(t_vector4f vector)
{
	t_internal_core		*internal;

	internal = (t_internal_core *)g_core.data;
	vector = m4f_mul_vector(&internal->screen_matrix, vector);
	vector.x /= vector.w;
	vector.y /= vector.w;
	vector.z /= vector.w;
	return (vector);
}
