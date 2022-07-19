#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player {
	int	x;
	int	y;
}	t_player;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*get_next_line(int fd);
char	**ft_read_map(void);
int ft_count_lines(int fd);
void	ft_print_matrix(char **mat);
void	ft_free(char **matrix);
void	ft_check_map(char **str, int mat_size);
char	*ft_strchr(const char *s, int c);
t_player	*search_player(char **mat);

#endif