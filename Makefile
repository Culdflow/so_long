CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
NAME = so_long
CFILES = main.c \
		render/draw.c \
		render/images.c \
		render/images_utils.c \
		utils/vectors.c \
		utils/vectors_utils.c \
		utils/operations.c \
		utils/libft.c \
		player/player.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		pathfinding/pathfinding.c \
		map/map.c \
		map/map_utils.c \
		map/map_check.c \
		map/map_collectibles.c \
		door/door.c \
		ft_printf/ft_manage.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putchar_fd.c \
		ft_printf/ft_putnbr_fd.c \
		ft_printf/ft_putstr_fd.c \
		error/error.c \
		main_utils.c

OBJS = ${CFILES:.c=.o}

.c.o:
	${CC} ${CFLAGS} -Iminilibx -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) ${CFLAGS} $(OBJS) -Lminilibx -lmlx -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz -o $(NAME)

fclean:	clean
	rm -rf ${NAME}

clean:
	rm -rf ${OBJS}

re:	fclean all

.PHONY: all clean fclean re