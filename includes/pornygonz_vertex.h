/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_vertex.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/07 00:27:08 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_VERTEX_H
# define PORNYGONZ_VERTEX_H

# include "pornygonz_internal.h"

t_bool		vertex_inside_frustum(t_vertex *v);
t_vertex	*vertex_new_init(void);
t_vertex	*vertex_new_cpy(t_vertex *src);
t_vertex	*vertex_lerp(t_vertex *v1, t_vertex *v2, float lerp_factor);
t_vertex	*vertex_new(t_vector4f p, t_vector4f c, t_vector2f t);

#endif
