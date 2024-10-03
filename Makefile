# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 12:49:01 by mparisse          #+#    #+#              #
#    Updated: 2023/10/02 22:41:54 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #===============================================================================#
#								SOURCES											  #
 #===============================================================================#

MAIN_DIR			= ./
PARSE_DIR			= ./parse/
CONTENT_FILE_DIR	= ./content_file/
RAY_TRACER_DIR	= ./raytracer/
HITS_DIR	= ./raytracer/Hits/
SETUP_DIR = ./raytracer/CameraNMatrixSetup/
COLOR_HITS_DIR = ./raytracer/ColorHits/
INTERSECTION = ./raytracer/Intersection/


INCLUDES		= includes
INCLUDESFT		= ./libft/${INCLUDES}

LIBS			=	-L/usr/X11/lib -lX11 -lXext -Lmlx  maxou_math/maxou_math.a mlx/libmlx_Linux.a
#FRAMEWORKS		=	-framework OpenGL -framework AppKit 	

# to activate the linux version comment out the variable FRAMEWORK
# and change the libmlx_Darwin.a to libmlx_Linux.a

SRC_FILES = $(addprefix $(MAIN_DIR), main.c	) \
			$(addprefix $(PARSE_DIR), parse.c parse_line.c set_data.c parse_utils.c) \
			$(addprefix $(CONTENT_FILE_DIR), content_file.c) \
			$(addprefix $(RAY_TRACER_DIR), mlx_utils.c prints.c) \
			$(addprefix $(HITS_DIR), hit_cy.c hit_sp.c hit_pl.c) \
			$(addprefix $(SETUP_DIR), build_camera.c build_transform_matrix.c) \
			$(addprefix $(COLOR_HITS_DIR), color_hit.c lighting.c) \
			$(addprefix $(INTERSECTION), normal_at.c lst_intersections.c)

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objects
OBJS = $(SRC_FILES:%.c=$(OBJS_DIR)/%.o)
DEPS = $(SRC_FILES:%.c=$(OBJS_DIR)/%.d)

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = cc
CFLAGS = -gdwarf-4 -O3 -I$(INCLUDES) -I$(INCLUDESFT) -Wall -Wextra -Werror -fenable-matrix #-fsanitize=address 
CDFLAGS = -MMD -MP

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = miniRT

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	make -C libft/
	make -C mlx/
	make -C maxou_math/
	$(CC) $(CFLAGS) $(OBJS) $(CLFLAGS) $(LIBS) $(FRAMEWORKS) libft/libft.a maxou_math/maxou_math.a -lm -o $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)/$(PARSE_DIR)
	mkdir -p $(OBJS_DIR)/$(CONTENT_FILE_DIR)
	mkdir -p $(OBJS_DIR)/$(RAY_TRACER_DIR)
	mkdir -p $(OBJS_DIR)/$(HITS_DIR)
	mkdir -p $(OBJS_DIR)/$(SETUP_DIR)
	mkdir -p $(OBJS_DIR)/$(COLOR_HITS_DIR)
	mkdir -p $(OBJS_DIR)/$(INTERSECTION)

$(OBJS) : $(OBJS_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(CDFLAGS) -c $< -o $@

norme:
	norminette $(SRC_FILES)
	norminette includes
	norminette libft

clean:
	rm -rf $(OBJS_DIR)
	make -C mlx/ clean
	make -C maxou_math/ clean
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C maxou_math/ fclean
	make -C libft/ fclean

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#.SILENT:
