/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/06 16:24:56 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_LINE_H
# define PORNYGONZ_LINE_H

void		draw_scan_line_inner(float *val, int val_size, int p[2]);
void		draw_scan_line(t_line *lines[2], t_list *ipls, int y);
void		draw_between_line(t_line *lines[2], t_list *ipls, t_bool swap);
void		line_do_step(t_line *l, int ipls_count);
void		line_setup(t_line *l, t_vertex *pts[2], t_list *ipls, int min);
void		line_delete(t_line *l);

#endif
