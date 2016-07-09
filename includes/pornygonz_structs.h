/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/09 22:28:28 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_STRUCT_H
# define PORNYGONZ_STRUCT_H

struct				s_uniform
{
	char			*name;
	void			*data;
	size_t			size;
};

struct				s_binding_point
{
	t_buffer		*buffer;
	unsigned int	bind_index;
};

struct				s_internal_core
{
	t_matrix4f		screen_matrix;
	t_binding_point	vertex_bind;
	t_binding_point	index_bind;
	t_binding_point	texture_bind;
	t_list			*vertex_buffers;
	t_list			*index_buffers;
	t_list			*texture_buffers;
	t_vs_callback	vs;
	t_fs_callback	fs;
	t_list			*uniforms;
	float			**depth_buffer;
};

struct				s_interpolant
{
	float			values[3];
	float			x_step;
	float			y_step;
};

struct				s_vertex
{
	t_vector4f		pos;
	t_vector4f		color;
	t_vector2f		tex_coords;
};

struct				s_line
{
	int				y_start;
	int				y_end;
	float			x_curr;
	float			x_step;
	float			*ipls_curr;
	float			*ipls_step;
};

struct				s_buffer
{
	void	*b;
	int		size;
};

struct			s_pornygonz_core
{
	void		*init;
	void		*window;
	void		*surface;
	void		*data;
	int			attribs;
	int			width;
	int			height;
};

#endif
