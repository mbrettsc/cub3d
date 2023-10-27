NAME = cub3d

SRC	= src/calculates.c src/init.c src/init_and_convert.c  src/init_map.c src/init_map_utils.c src/init_player.c src/main.c src/map_check.c src/map_check_utils.c \
			src/map_is_surrounded.c src/movements.c src/ray_casting.c src/utils.c

FLAGS = gcc -Wall -Wextra -Werror

RM = rm -f

all: $(NAME) $(SRCS)

$(NAME): $(SRCS)
	make -C libft
	make -C mlx
	$(FLAGS)  -framework OpenGL -framework AppKit mlx/libmlx.a libft/libft.a $(SRC) -o $(NAME)

clean: 
	$(RM) $(NAME)

fclean: clean
	make fclean -C libft
	make clean -C mlx
re: fclean all

.PHONY: clean fclean all re