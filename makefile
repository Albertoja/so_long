SRCS = main.c read_map.c get_next_line.c count_lines.c so_long_utils.c check_map.c search_player_col.c key_detect.c win.c print_map.c spawn_enemy.c

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

MINILIB	= mlx/libmlx.a

PATHMLIB	= mlx/

PATHLIB	= libft/

LIBFT	= libft/libft.a

CC	= gcc

RM	= rm -f

CFLAGS	= -I. -Wall -Wextra -Werror -Imlx #-g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@make -C ${PATHLIB}
				@make -C ${PATHMLIB}
				${CC} ${CFLAGS} ${MINILIB} ${LIBFT} ${OBJS} -L./mlx -lmlx -framework OpenGL -framework AppKit -L. -o ${NAME}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				@make clean -C ${PATHMLIB}
				${RM} ${OBJS}

fclean: 	clean
				@make clean
				${RM} ${LIBFT}
				${RM} ${MINILIB}
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
