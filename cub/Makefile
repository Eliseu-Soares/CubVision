NAME_BONUS = cub3D_bonus

SRC_BONUS = ./main_bonus.c \
	./src/validation/check_args_bonus.c \
	./src/utils/pixel_utils_bonus.c \
	./src/validation/validation_bonus.c \
	./src/utils/print_error_bonus.c \
	./src/utils/free_split_bonus.c \
	./src/utils/utils_map_bonus.c \
	./src/utils/color_utils_bonus.c \
	./src/utils/strncmp_with_space_bonus.c \
	./src/utils/utils_bonus.c \
	./src/validation/validation_extensions_bonus.c \
	./src/validation/permission_and_empty_file_bonus.c \
	./src/validation/validation_map_bonus.c \
	./src/utils/validation_map_utils.c \
	./src/validation/validation_parse_bonus.c \
	./src/map/load_map_bonus.c \
	./src/parse/parser_bonus.c \
	./src/parse/parser_color_part2_bonus.c \
	./src/parse/parser_texture_bonus.c \
	./src/parse/parser_color_bonus.c \
	./src/event/key_bonus.c \
	./src/engine/raycasting_bonus.c \
	./src/engine/render_bonus.c \
	./src/engine/minimap_bonus.c \
	./src/destroy/destroyer_bonus.c \
	./src/init/init_cubo_bonus.c \
	./src/init/texture_bonus.c \
	./src/engine/texture_bonus.c \
	./src/event/mouse_bonus.c \
	./src/network/udp_receive.c

CC = cc
RM = rm -rf
MLX= -Lminilibx-linux -lmlx -lXext -lX11 -lm
DEBUG_FLAG = -g
CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAG)
HEADER = ./cubo.h ./config.h ./src/utils/utils.h ./src/event/events.h ./src/engine/engine.h
HEADER_BONUS = ./cubo_bonus.h ./config_bonus.h ./src/utils/utils_bonus.h ./src/event/events_bonus.h ./src/engine/engine_bonus.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C minilibx-linux
	make -C ./lib/libft 
	make -C ./lib/ft_printf
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(MLX) ./lib/libft/libft.a ./lib/ft_printf/libftprintf.a

$(OBJ): $(HEADER)
$(OBJ_BONUS): $(HEADER_BONUS)

clean:
	make clean -C minilibx-linux
	make clean -C ./lib/libft 
	make clean -C ./lib/ft_printf
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	make fclean -C ./lib/libft 
	make fclean -C ./lib/ft_printf
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

PHONY: all clean fclean re
