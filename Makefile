NAME = cub3d

CC = gcc -Wall -Wextra -Werror
DY = libmlx.dylib
A = libmlx.a
FT = libft.a
# OBJS = $(SRCS:.c=.o)
SRCS = start.c

all: $(NAME)

$(NAME) :
	make -C ./libft all bonus
	make -C ./minilibx_mms all
	make -C ./minilibx_opengl all
	cp ./minilibx_mms/libmlx.dylib .
	cp ./minilibx_opengl/libmlx.a .
	cp ./libft libft.a .
	gcc ./*.c ./get_next_line/*.c -o $@ -Wall -Wextra -Werror \
	-L. -lft -I./libft -I./get_next_line -I. -lm \
	-L. -lmlx -framework Opengl -framework AppKit -lz -fsanitize=address
	./cub3d test.cub
	rm cub3d

clean:
	make -C ./minilibx_opengl clean
	make -C ./minilibx_mms clean
	make -C ./libft fclean

fclean: clean
	rm cub3d

re: fclean all


bonus: all
