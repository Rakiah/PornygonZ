/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_clipper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/06 16:30:25 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_CLIPPER_H
# define PORNYGONZ_CLIPPER_H

#include "pornygonz_internal.h"

t_list	*clip_triangle(t_vertex *v1, t_vertex *v2, t_vertex *v3);
t_bool	clip_axis(t_list *vertices, t_list *tmp, int index);
void	clip_polygon_index(t_list *verts, t_list *result, int index, float side);

#endif
