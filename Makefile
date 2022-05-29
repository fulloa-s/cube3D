# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 12:13:43 by fulloa-s          #+#    #+#              #
#    Updated: 2021/04/09 14:05:55 by fulloa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	check_map.c \
				check_map2.c \
				check_var.c \
				check_var2.c \
				movement.c \
				cub3d_utils.c \
				cub3d.c \
				init.c \
				bitmap.c \
				sprite.c \
				rotation.c \
				minimap.c \
				player_orientation.c \
				keycode.c \
				get_next_line.c \
				get_next_line_utils.c \
				mlx.c \
				parsing_map.c \
				parsing_map2.c \
				parsing_res_4var.c \
				parsing_s_f_c.c \
				raycasting.c \
				raycasting2.c \
				raycasting3.c \
				error.c

SRCS_BONUS	=	./bonus/check_map_bonus.c \
				./bonus/check_map2_bonus.c \
				./bonus/check_var_bonus.c \
				./bonus/check_var2_bonus.c \
				./bonus/movement_bonus.c \
				./bonus/cub3d_utils_bonus.c \
				./bonus/cub3d_bonus.c \
				./bonus/init_bonus.c \
				./bonus/bitmap_bonus.c \
				./bonus/sprite_bonus.c \
				./bonus/rotation_bonus.c \
				./bonus/minimap_bonus.c \
				./bonus/player_orientation_bonus.c \
				./bonus/keycode_bonus.c \
				./bonus/get_next_line_bonus.c \
				./bonus/get_next_line_utils_bonus.c \
				./bonus/mlx_bonus.c \
				./bonus/parsing_map_bonus.c \
				./bonus/parsing_map2_bonus.c \
				./bonus/parsing_res_4var_bonus.c \
				./bonus/parsing_s_f_c_bonus.c \
				./bonus/raycasting_bonus.c \
				./bonus/raycasting2_bonus.c \
				./bonus/raycasting3_bonus.c \
				./bonus/error_bonus.c

MLX_F		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME		=	cub3D

CFLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJCS		=	$(SRCS:.c=.o)

OBJCS_BONUS	=	$(SRCS_BONUS:.c=.o)

.c.o		:
				@printf "\r\033[33m[CONVERTING FILES ...]"
				@$(CC) $(CFLAGS) -c $<

all			:	$(NAME)
			
$(NAME)		:	$(OBJCS)
				@echo "\n\033[33m[COMPILING MLX ...]" "\x1b[0m"
				@$(MAKE) -C ./mlx > /dev/null
				@cp ./mlx/libmlx.dylib ./
				@echo "\033[33m[COMPILING CUB3D ...]"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJCS) $(MLX_F)
				@echo "\x1b[32;01m[DONE!]"

bonus		:	$(OBJCS_BONUS)
				@echo "\n\033[33m[COMPILING MLX ...]" "\x1b[0m"
				@$(MAKE) -C ./mlx > /dev/null
				@cp ./mlx/libmlx.dylib ./
				@echo "\033[33m[COMPILING CUB3D ...]"
				@mv *_bonus.o ./bonus/
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJCS_BONUS) $(MLX_F)
				@echo "\x1b[32;01m[DONE!]"

run			:	$(NAME)
				./cub3D "./map.cub"

runbonus	:	bonus
				./cub3D "bonus/map_bonus.cub"

save		:	$(NAME)
				./cub3D "./map.cub" "--save"

savebonus	:	bonus
				./cub3D "bonus/map_bonus.cub" "--save"

clean		:
				@$(MAKE) clean -C ./mlx > /dev/null
				@rm -f libmlx.dylib
				@rm -f $(OBJCS)
				@rm -f $(OBJCS_BONUS)
				@rm -f ./screenshot.bmp


fclean		:	clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re run