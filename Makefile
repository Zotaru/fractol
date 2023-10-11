# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonier <amonier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 22:27:42 by amonier           #+#    #+#              #
#    Updated: 2023/10/11 15:31:18 by amonier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

NAME_BONUS	= fractol_bonus

DIR_SRCS	= srcs

DIR_BONUS	= srcs_bonus

DIR_OBJS	= obj

DIR_OBJS_B	= obj_bonus

SRCS_NAMES		=	\
	main.c			\
	my_mlx_pixel_put.c	\
	parsing/parsing.c					\
	parsing/bad_command.c				\
	parsing/check_str.c					\
	parsing/ft_atof.c					\
	hook/esc.c					\
	hook/cross.c				\
	hook/mouse_hook.c			\
	hook/all_hook.c				\
	action/mandel_zoom.c					\
	action/clear_image.c					\
	action/julia_zoom.c					\
	action/mandel_dezoom.c				\
	action/julia_dezoom.c					\
	fractales/utils/calculate_real_unreal.c				\
	fractales/utils/create_fract_trgb.c					\
	fractales/mandel/calcule_fractole_mandel.c				\
	fractales/mandel/my_mlx_mandel_fractol.c				\
	fractales/julia/calcule_fract_julia.c						\
	fractales/julia/my_mlx_julia_fract.c						\


BONUS_SRCS_NAMES	=	\
	main.c			\
	my_mlx_pixel_put.c	\
	parsing/parsing.c					\
	parsing/bad_command.c				\
	parsing/check_str.c					\
	parsing/ft_atof.c					\
	hook/cross.c				\
	hook/mouse_hook.c			\
	hook/all_hook.c				\
	action/mandel_zoom.c					\
	action/clear_image.c					\
	action/julia_zoom.c					\
	action/mandel_dezoom.c				\
	action/julia_dezoom.c					\
	fractales/utils/calculate_real_unreal.c				\
	fractales/utils/create_fract_trgb.c					\
	fractales/mandel/calcule_fractole_mandel.c				\
	fractales/mandel/my_mlx_mandel_fractol.c				\
	fractales/julia/calcule_fract_julia.c						\
	fractales/julia/my_mlx_julia_fract.c						\
	hook/keyboard.c			\
	fractales/newton/my_mlx_newton_fractol.c	\
	action/newton_zoom.c					\
	action/newton_dezoom.c				\
	action/right_arrow.c				\
	action/left_arrow.c					\
	action/top_arrow.c					\
	action/down_arrow.c					\
	action/switch_color.c				\
	fractales/newton/calcule_fractole_newton.c		\
	

OBJS_NAMES	= ${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	= ${BONUS_SRCS_NAMES:.c=.o}

SRCS		= $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B		= $(addprefix $(DIR_BONUS)/,$(BONUS_SRCS_NAMES))

OBJS		= $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_BONUS	= $(addprefix $(DIR_OBJS_B)/,$(OBJS_NAMES_B))

CC			= cc -g3
CFLAGS		= -Wall -Wextra -Werror -O2 -O3 -march=native -funroll-loops -ffast-math -fomit-frame-pointer
CFLAGSBONUS	= -pthread
HEAD		= -IIncludes -Iminilibx-linux
MLX			= minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

RM			= rm -f
# MAKEFLAGS	= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(MLX) -lXext -lX11 -lm -lz -o $(NAME)
	$(info CREATED $(NAME))
	@echo "\033[34;5mfractol\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
	$(info CREATED $@)

bonus: all $(NAME_BONUS)
	
$(DIR_OBJS_B)/%.o: $(DIR_BONUS)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CFLAGSBONUS) $(HEAD) -c $< -o $@
	$(info CREATED $@)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(CFLAGSBONUS) $(OBJS_BONUS) libft/libft.a $(MLX) -lXext -lX11 -lm -lz -o $(NAME_BONUS)
	$(info CREATED $(NAME_BONUS))
	@echo "\033[34;5mfractol BONUS\033[0m"


clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT:
