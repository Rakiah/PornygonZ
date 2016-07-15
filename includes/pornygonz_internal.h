/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 13:26:46 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_INTERNAL_H
# define PORNYGONZ_INTERNAL_H

# include <SDL.h>
# include "rstd.h"
# include "rmath.h"
# include "rcontainers_lists.h"
# include "pornygonz.h"
# include "pornygonz_defines.h"
# include "pornygonz_typedefs.h"
# include "pornygonz_structs.h"
# include "pornygonz_utils.h"
# include "pornygonz_clipper.h"
# include "pornygonz_attributes.h"
# include "pornygonz_rasterizer.h"
# include "pornygonz_draw_types.h"
# include "pornygonz_vertex.h"
# include "pornygonz_line.h"
# include "pornygonz_line_drawing.h"
# include "pornygonz_interpolant.h"
# include "pornygonz_interpolants_types.h"

t_vector4f	screen_coordinates_convert(t_vector4f vector);
t_vector4f	process_vertex_shader(void *vert);
t_vector4f	process_fragment_shader(void *vert);
void		buffer_add_data(t_buffer *buf, void *data, size_t size_data);

extern t_pornygonz_core	g_core;

#endif
