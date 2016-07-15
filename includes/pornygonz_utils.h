/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:18:48 by bkabbas           #+#    #+#             */
/*   Updated: 2016/07/15 13:25:36 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_UTILS_H
# define PORNYGONZ_UTILS_H

void		buffer_add_data(t_buffer *buf, void *d, size_t s);
void		uniform_delete(t_uniform *uniform);
void		buffer_delete(t_buffer *buf);
t_vector4f	screen_coordinates_convert(t_vector4f vector);

#endif
