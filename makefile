SRCS = main.c read_map.c get_next_line.c get_next_line_utils.c count_lines.c print_matrix.c so_long_utils.c check_map.c search_player_col.c print_utils.c key_detect.c win.c

LIBFT_PATH = libft/

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address

GCC	= gcc

LIBFT_PATH = libft/

RM	= rm -f

all:		$(NAME)

.c.o:
	$(GCC) $(CFLAGS)  -Imlx -c $< -o $@ -I$(LIBFT_PATH)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH) --silent
	$(CC) -o $(NAME) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I./libft -L./libft -lft

clean:		
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		make -C $(LIBFT_PATH) fclean 

re:		fclean all

.PHONY:		all clean fclean re 