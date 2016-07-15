/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 12:17:36 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_H
# define PORNYGONZ_H

# include <stdlib.h>

typedef enum e_draw_type	t_draw_type;
typedef enum e_element_type	t_element_type;
typedef void	(*t_vs_callback)(const float *in_vertex, float out_position[4]);
typedef void	(*t_fs_callback)(const float *in_vertex, float out_color[4]);

enum	e_draw_type
{
	PORNYGONZ_TRIANGLES
};

enum	e_element_type
{
	PORNYGONZ_SHORT,
	PORNYGONZ_UNSIGNED_SHORT,
	PORNYGONZ_INT,
	PORNYGONZ_UNSIGNED_INT,
	PORNYGONZ_LONG,
	PORNYGONZ_UNSIGNED_LONG
};

# define PORNYGONZ_DEPTH_BUFFER 1
# define PORNYGONZ_COLOR 2
# define PORNYGONZ_TEXTURE_COORDS 4

/*
**		function: pornygonz_init
**		initialize everything that have to be done
**		before any pornygonz function is created.
**		return an int to be tested to check if the initialization
**		worked correctly or not
**		parameters: (void)
*/
int				pornygonz_init(void);

/*
**		function: pornygonz_quit
**		free everything that was initialized this is usually called just
**		before the application close.
**		return void
**		parameters: (void)
*/
void			pornygonz_quit(void);

/*
**		function: pornygonz_create_window
**		create a window and stock it inside the global core structure.
**		return an int to be tested to check if the creation
**		worked correctly or not.
**		parameters: (int, int)
**		width: typeof int, represent the width of the window
**		height: typeof int, represent the height of the window
*/
int				pornygonz_create_window(int width, int height);

/*
**		function: pornygonz_get_window
**		hook for the window stocked inside the global core structure
**		return the instance of the current used pornygonz window
**		parameters: (void)
*/
void			*pornygonz_get_window(void);

/*
**		function: pornygonz_destroy_window
**		free the window stocked inside the global core structure
**		return void
*/
void			pornygonz_destroy_window(void);

/*
**		function: pornygonz_swap_buffer
**		blit the rendered surface to the screen
**		usually called just after we rendered
**		return void
**		parameters: (void)
*/
void			pornygonz_swap_buffer(void);

/*
**		function: pornygonz_clear
**		clear the rendered surface and the depth buffer
**		usually called just before we render again
**		return void
**		parameters: (void)
*/
void			pornygonz_clear(void);

/*
**		function: pornygonz_create_vertex_array
**		create a vertex array in the pornygonz memory
**		that can be used with the others corresponding methods
**		return unsigned int which is the ID of the array
**		parameters: (void)
*/
unsigned int	pornygonz_create_vertex_array(void);

/*
**		function: pornygonz_delete_vertex_array
**		delete an array in the pornygonz memory
**		return void
**		parameters: (unsigned int)
**		uid: typeof unsigned int, represent the index of
**		the array you want to free
*/
void			pornygonz_delete_vertex_array(unsigned int uid);

/*
**		function: pornygonz_bind_vertex_array
**		bind a specific vertex buffer to the current active array
**		pornygonz must use in the next calls
**		return void
**		parameters: (unsigned int)
**		uid: typeof unsigned int, represent the array you want to bind
**		to the VERTEX_ARRAY
*/
void			pornygonz_bind_vertex_array(unsigned int uid);

/*
**		function: pornygonz_add_vertex_data
**		add data to the current bound buffer
**		return void
**		parameters: (void *, size_t)
**		array: typeof void *, represent the bytes you want to add
**		array_size: typeof size_t, represent the size of the array
*/
void			pornygonz_add_vertex_data(void *array, size_t array_size);

/*
**		function: pornygonz_enable_vertex_attribute
**		enable specifics attribute to be used when drawing
**		see attributes defines to see what you can use
**		parameters: (int)
**		attributes: typeof int, flag integer containing defines
*/
void			pornygonz_enable_vertex_attribute(int attribute);

/*
**		function: pornygonz_enable_vertex_attribute
**		disable specifics attribute to be used when drawing
**		see attributes defines to see what you can use
**		parameters: (int)
**		attributes: typeof int, flag integer containing defines
*/
void			pornygonz_disable_vertex_attribute(int attribute);

/*
**		function: pornygonz_create_index_array
**		create a index array in the pornygonz memory
**		that can be used with the others corresponding methods
**		return unsigned int which is the ID of the array
**		parameters: (void)
*/
unsigned int	pornygonz_create_index_array(void);

/*
**		function: pornygonz_delete_index_array
**		delete a index array in the pornygonz memory
**		return void
**		parameters: (unsigned int)
**		uid: typeof unsigned int,
**		represent the index of the array you want to free
*/
void			pornygonz_delete_index_array(unsigned int uid);

/*
**		function: pornygonz_bind_index_array
**		bind a specific vertex index buffer to the current active array
**		pornygonz must use in the next calls
**		return void
**		parameters: (unsigned int)
**		uid: typeof unsigned int, represent the array you want to bind
*/
void			pornygonz_bind_index_array(unsigned int uid);

/*
**		function: pornygonz_add_index_data
**		add data to the current bound buffer
**		return void
**		parameters: (void *, size_t)
**		array: typeof void *, represent the bytes you want to add
**		array_size: typeof size_t, represent the size of the array
*/
void			pornygonz_add_index_data(void *array, size_t array_size);

/*
**		function: pornygonz_create_texture
**		create a texture in the pornygonz memory
**		that can be used with the others corresponding method
**		return unsigned int which is the ID of the texture
**		parameters: (int, int, int)
**		width: typeof int, represent the width of the texture
**		height: typeof int, represent the height of the texture
**		bpp : typeof int, represent how many bytes there is in one pixel
*/
unsigned int	pornygonz_create_texture(int width, int height, int bpp);

/*
**		function: pornygonz_delete_texture
**		delete a texture in the pornygonz memory
**		return void
**		parameters: (unsigned int)
**		uid: typeof unsigned int, represent the ID of
**		the texture you want to free
*/
void			pornygonz_delete_texture(unsigned int uid);

/*
**		function: pornygonz_bind_texture
**		bind a specific texture to the current active texture
**		pornygonz must use in the next calls
**		return void
**		parameters: (unsigned int)
**		uid: typeof unsigned int, represent the texture you want to bind
*/
void			pornygonz_bind_texture(unsigned int uid);

/*
**		function: pornygonz_add_texture_data
**		add data to the current bound texture
**		return void
**		parameters: (void *, size_t)
**		pixels: typeof void *, represent the bytes you want to add
**		pixels_size: typeof size_t, represent the size of the pixels array
*/
void			pornygonz_add_texture_data(void *pixels, size_t pixels_size);

/*
**		function: pornygonz_get_texture_pixel
**		get the pixel at U/V coordinates on the bound texture
**		and fill the "pixel" array with it
**		return void
**		parameters: (float, float, float[4])
**		u: texture coordinate U (also called x)
**		v: texture coordinate V (also called y)
**		out: filled by the function with ARGB components
*/
void			pornygonz_get_texture_pixel(float u, float v, float out[4]);

/*
**		function: pornygonz_draw_arrays
**		draw to the pornygonz surface the vertex array
**		return void
**		parameters: (t_draw_type, int, int);
**		type: typeof t_draw_type, drawing type pornygonz should use
**		first: typeof int, the point where pornygonz should start drawing
**		count: typeof int, how many vertices pornygonz should draw
*/
void			pornygonz_draw_arrays(t_draw_type type, int first, int count);

/*
**		function: pornygonz_draw_elements
**		draw to the pornygonz surface the vertex array, based on bound index
**		return void
**		parameters: (t_draw_type, t_element_type, int, int);
**		draw_type: typeof t_draw_type, drawing type pornygonz
**		should use (see t_draw_type doc)
**		indices_type: typeof t_element_type, the type pornygonz should
**		cast indices into
**		first: typeof int, the point where pornygonz should start drawing
**		count: typeof int, how many vertices pornygonz should draw
*/
void			pornygonz_draw_elements(t_draw_type draw_type,
										t_element_type indices_type,
										int first, int count);

/*
**		function: pornygonz_bind_vertex_shader
**		bind a custom vertex shader function with a specific prototype
**		parameters: (t_shader_callback)
**		shader: typeof t_shader_callback, function pointer to the
**		custom shader
*/
void			pornygonz_bind_vertex_shader(t_vs_callback shader);

/*
**		function: vertex_shader_default
**		default vertex shader function, always the in_vert base position
**		parameters: (t_vs_callback definition)
*/
void			vertex_shader_default(const float *in_vert, float out_pos[4]);

/*
**		function: pornygonz_bind_fragment_shader
**		bind a custom fragment shader function with a specific prototype
**		parameters: (t_shader_callback)
**		shader: typeof t_shader_callback, function pointer to the
**		custom shader
*/
void			pornygonz_bind_fragment_shader(t_fs_callback shader);

/*
**		function: fragment_shader_default
**		default fragment shader function, always return
**		a plain white color
**		parameters: (t_fs_callback definition)
*/
void			fragment_shader_default(const float *in_vert, float out_col[4]);

/*
**		function: pornygonz_add_uniform
**		add a uniform that can be used in shaders
**		parameters: (char *, void *, size_t)
**		name: typeof char *, name of the uniform, used to retrieve data
**		data: typeof void *, data of the uniform
**		size: typeof size_t, size of data
*/
void			pornygonz_add_uniform(char *name, void *data, size_t size);

/*
**		function: pornygonz_get_uniform
**		find a specific uniform based on the name and fill in size
**		the size in bytes of the uniform
**		parameters: (char *, size_t *)
**		name: name of the uniform to find
**		size: pointer that will be set to the size of the uniform
**		return: the uniform or NULL if not found
*/
void			*pornygonz_get_uniform(char *name, size_t *size);

#endif
