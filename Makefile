# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:30:01 by bkabbas           #+#    #+#              #
#    Updated: 2016/07/15 13:27:55 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpornygonz.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIMIZE = yes
PROF = no
DEBUG = no

# Paths
PATH_SDL2 = ../SDL2
PATH_RSTD = ../rstd
PATH_RMATH = ../rmath
PATH_RCONTAINERS = ../rcontainers

PATH_HEADERS = includes
PATH_SRC = sources
PATH_OBJ = objects
PATH_HEADERS = includes

# Dependencies
CFLAGS += -I $(PATH_SDL2)/includes
CFLAGS += -I $(PATH_RSTD)/includes
CFLAGS += -I $(PATH_RMATH)/includes
CFLAGS += -I $(PATH_RCONTAINERS)/includes

CFLAGS += -I $(PATH_HEADERS)

# Debug
ifeq ($(DEBUG), yes)
	CFLAGS += -g -O0
endif

# Optimization
ifeq ($(PROF), yes)
	CFLAGS += -pg
endif

# Optimization
ifeq ($(OPTIMIZATION), yes)
	CFLAGS += -O3
endif

vpath %.c $(PATH_SRC)


SHADERS += pornygonz_vertex_shaders.c
SHADERS += pornygonz_fragment_shaders.c
SHADERS += pornygonz_uniforms.c

ARRAYS += pornygonz_vertex_array.c
ARRAYS += pornygonz_index_array.c
ARRAYS += pornygonz_texture.c
ARRAYS += pornygonz_attributes.c

RENDERING += pornygonz_core.c
RENDERING += pornygonz_window.c
RENDERING += pornygonz_renderer.c
RENDERING += pornygonz_draw_types.c
RENDERING += pornygonz_rasterizer.c
RENDERING += pornygonz_vertex.c
RENDERING += pornygonz_interpolant.c
RENDERING += pornygonz_line.c
RENDERING += pornygonz_line_drawing.c
RENDERING += pornygonz_clipper.c
RENDERING += pornygonz_utils.c
RENDERING += pornygonz_interpolants_types.c

SOURCES += $(RENDERING)
SOURCES += $(ARRAYS)
SOURCES += $(SHADERS)

INCLUDES += pornygonz.h
INCLUDES += pornygonz_line.h
INCLUDES += pornygonz_line_drawing.h
INCLUDES += pornygonz_typedefs.h
INCLUDES += pornygonz_structs.h
INCLUDES += pornygonz_defines.h
INCLUDES += pornygonz_utils.h
INCLUDES += pornygonz_attributes.h
INCLUDES += pornygonz_clipper.h
INCLUDES += pornygonz_rasterizer.h
INCLUDES += pornygonz_vertex.h
INCLUDES += pornygonz_internal.h
INCLUDES += pornygonz_draw_types.h
INCLUDES += pornygonz_interpolant.h
INCLUDES += pornygonz_interpolants_types.h

# Headers
HEADERS += $(addprefix $(PATH_HEADERS)/, $(INCLUDES))

# Objects
OBJECTS += $(addprefix $(PATH_OBJ)/, $(RENDERING:%.c=%.o))
OBJECTS += $(addprefix $(PATH_OBJ)/, $(SHADERS:%.c=%.o))
OBJECTS += $(addprefix $(PATH_OBJ)/, $(ARRAYS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo library linked correctly

$(OBJECTS): $(HEADERS) | $(PATH_OBJ)
$(OBJECTS): $(PATH_OBJ)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(PATH_OBJ):
	@-mkdir -p $@

clean:
	@rm -rf $(PATH_OBJ)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@echo removed library

re: fclean all

.PHONY: all clean fclean re
