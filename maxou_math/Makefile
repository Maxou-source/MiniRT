# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 17:44:55 by mparisse          #+#    #+#              #
#    Updated: 2023/09/21 17:15:28 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maxou_math.a 

################################################################################
#                                  COMPILATION                                 #
################################################################################

CC = clang

CFLAGS = -Wall -Werror -Wextra -fenable-matrix

CDFLAGS = -MMD -MP

INCLUDES = includes
INCLUDESMM = ./includes


################################################################################
#                                  DIRECTORIES                                 #
################################################################################


MATRIX_DIR = matrix
TUPLES_DIR = tuples


SRCS_FILES = $(addprefix matrix/, \
				determinants.c  ops_matrix_2.c ops_matrix.c prints.c subs_matrix.c) \
				\
				$(addprefix tuples/, \
				ops_tuples.c ops_tuples_2.c ops_tuples_3.c color_utils.c) 
OBJS_DIR = .objets

OBJS = $(SRCS_FILES:%.c=$(OBJS_DIR)/%.o)


################################################################################
#                                  RULES                                       #
################################################################################

all :	$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) ${OBJS}

$(OBJS_DIR):
	mkdir	$(OBJS_DIR)
	mkdir	$(OBJS_DIR)/$(MATRIX_DIR)
	mkdir	$(OBJS_DIR)/$(TUPLES_DIR)

# $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJS) : $(OBJS_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(CDFLAGS) -I$(INCLUDES) -I$(INCLUDESMM) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY = all fclean re clean
