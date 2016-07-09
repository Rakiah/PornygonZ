/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_rasterizer.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/06 16:24:56 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_RASTERIZER_H
#define PORNYGONZ_RASTERIZER_H

void	process_polygon(t_vertex *v1, t_vertex *v2, t_vertex *v3);
void	process_triangle(t_vertex v1, t_vertex v2, t_vertex v3);
void	draw_triangle(t_vertex *verts[3]);
void	triangle_to_lines(t_vertex *verts[3]);
t_bool	calculate_triangle_side(t_vector4f *a, t_vector4f *b, t_vector4f *c);

#endif
