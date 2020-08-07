# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/12 20:16:14 by lverdoes      #+#    #+#                  #
#    Updated: 2020/06/23 09:12:37 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC = ./mandatory/main/main.c \
	./mandatory/utilities/utilities.c \
	./mandatory/utilities/errors_and_free.c \
	./mandatory/screenshot/screenshot.c \
	./mandatory/check_input/check_input.c \
	./mandatory/check_input/parse_lines.c \
	./mandatory/check_input/get_map_data.c \
	./mandatory/check_input/get_res_tex_col_data.c \
	./mandatory/check_input/flood_fill.c \
	./mandatory/engine/render_next_frame.c \
	./mandatory/engine/track_key_input.c \
	./mandatory/engine/movement.c \
	./mandatory/engine/view.c \
	./mandatory/engine/calc_ray_dir.c \
	./mandatory/engine/calc_wall_height.c \
	./mandatory/engine/draw_walls.c \
	./mandatory/engine/draw_sprites.c \
	./mandatory/engine/calc_sprite_dist.c \
	./mandatory/init_structs/init_data_struct.c \
	./mandatory/init_structs/init_image_struct.c \
	./mandatory/init_structs/init_position_struct.c \
	./mandatory/init_structs/init_textures_struct.c

SRC_BONUS = ./bonus/main/main_bonus.c \
	./bonus/utilities/utilities_bonus.c \
	./bonus/utilities/errors_and_free_bonus.c \
	./bonus/screenshot/screenshot_bonus.c \
	./bonus/check_input/check_input_bonus.c \
	./bonus/check_input/parse_lines_bonus.c \
	./bonus/check_input/get_map_data_bonus.c \
	./bonus/check_input/get_res_tex_col_data_bonus.c \
	./bonus/check_input/flood_fill_bonus.c \
	./bonus/engine/render_next_frame_bonus.c \
	./bonus/engine/track_key_input_bonus.c \
	./bonus/engine/movement_bonus.c \
	./bonus/engine/view_bonus.c \
	./bonus/engine/calc_ray_dir_bonus.c \
	./bonus/engine/calc_wall_height_bonus.c \
	./bonus/engine/draw_walls_bonus.c \
	./bonus/engine/draw_background_bonus.c \
	./bonus/engine/draw_sprites_bonus.c \
	./bonus/engine/calc_sprite_dist_bonus.c \
	./bonus/engine/coin_collect_bonus.c \
	./bonus/engine/next_level_bonus.c \
	./bonus/engine/jump_crouch_bonus.c \
	./bonus/engine/mouse_buttons_bonus.c \
	./bonus/engine/draw_hud_bonus.c \
	./bonus/init_structs/init_data_struct_bonus.c \
	./bonus/init_structs/init_image_struct_bonus.c \
	./bonus/init_structs/init_position_struct_bonus.c \
	./bonus/init_structs/init_textures_struct_bonus.c \
	./bonus/init_structs/init_mouse_struct_bonus.c \
	./bonus/init_structs/init_game_struct_bonus.c \
	./bonus/init_structs/init_hud_struct_bonus.c \
	./bonus/init_structs/init_keyboard_struct_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS =	$(SRC_BONUS:.c=.o)

CC = gcc -Wall -Wextra -Werror

LIBFT = libft.a

LIBFT_INCLUDES = libft.h

MLX_FLAGS = -L. -lmlx -framework OpenGL -framework AppKit

MLX = libmlx.dylib

INCLUDES = ./headers/cub3d.h \
		./headers/struct.h \
		./headers/cub3d_bonus.h \
		./headers/struct_bonus.h

all: $(NAME)

libmlx.dylib:
	@cd mlx && make && mv $(MLX) ..

libft.a:
	cd ./libft && make bonus

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(MLX_FLAGS) -o $(NAME) $(OBJ) ./libft/$(LIBFT)
%.o: %.c
	$(CC) -Imlx -Iinc -Ilibft -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJ_BONUS)
	@$(CC) $(MLX_FLAGS) -O3 -o $(NAME_BONUS) $(OBJ_BONUS) ./libft/$(LIBFT)

.PHONY: clean fclean re

norm:
	@norminette $(SRC) $(SRC_BONUS) $(INCLUDES) Makefile
	@cd ./libft && make norm

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ_BONUS)
	@/bin/rm -f *.o
	@/bin/rm -f ./*/*/*.o
	@/bin/rm -f *~
	@/bin/rm -f .DS_Store

fclean: clean
	@/bin/rm -f $(NAME) $(MLX)
	@/bin/rm -f $(NAME_BONUS)
	@/bin/rm -f save.bmp
	@cd ./libft && make fclean

re: fclean all

bob: bonus
	./cub3D_bonus ./maps_bonus/1_map_bonus.cub
