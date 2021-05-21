NAME = cub3d

CC = gcc -Wall -Wextra -Werror
DY = libmlx.dylib
A = libmlx.a
FT = libft.a
SRCS = start.c

all: $(NAME)

$(NAME) :
	make -C ./libft all bonus
	make -C ./minilibx_mms all
	make -C ./minilibx_opengl all
	cp ./minilibx_mms/libmlx.dylib .
	cp ./minilibx_opengl/libmlx.a .
	cp ./libft/libft.a .
	cp ./minilibx_mms/mlx.h .
	gcc ./*.c ./get_next_line/*.c -o $@ -Wall -Wextra -Werror \
	-L. -lft -I./libft -I./get_next_line -I. -lm \
	-L. -lmlx -framework Opengl -framework AppKit -lz

clean:
	make -C ./minilibx_opengl clean
	make -C ./minilibx_mms clean
	make -C ./libft fclean
	rm -f libft.a libmlx.a mlx.h

fclean: clean
	rm -f cub3d libmlx.dylib

re: fclean all
