/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_line_drawing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:04:59 by bkabbas           #+#    #+#             */
/*   Updated: 2016/07/15 13:06:05 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_LINE_DRAWING_H
# define PORNYGONZ_LINE_DRAWING_H

void	generate_fragment(float *fragment, float *values);
void	draw_scan_line_inner(float *value, int pos[2]);
void	draw_scan_line(t_line *lines[2], t_list *ipls, int y);
void	draw_between_line(t_line *lines[2], t_list *ipls, t_bool s);

#endif
