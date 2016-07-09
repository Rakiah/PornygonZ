/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_interpolants_types.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/06 16:24:56 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_INTERPOLANTS_TYPES_H
# define PORNYGONZ_INTERPOLANTS_TYPES_H

t_interpolant	*ipl_depth_buffer(t_vertex *v[3]);
t_interpolant	*ipl_color(t_vertex *v[3], int component_index);
t_interpolant	*ipl_texture_coords(t_vertex *v[3], int component_index);
t_interpolant	*ipl_texture_perspective(t_vertex *v[3]);

#endif
