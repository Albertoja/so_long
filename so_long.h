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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map {
	char	**map;
}	t_map;

typedef struct s_all{
	//void		*mlx_win;
	//void		*mlx;
	int			col;
	int			win;
	t_player	player;
	t_data		data;
	t_vars		vars;
	t_map		map;
}				t_all;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*get_next_line(int fd);
char	**ft_read_map();
int ft_count_lines(int fd);
void	ft_print_matrix(t_all *all);
void	ft_free(char **matrix);
void	ft_check_map(char **str, int mat_size);
char	*ft_strchr(const char *s, int c);
void	search_player_col(t_all *all);
int	key_hook(int keycode, t_vars *vars);
int	key_detect(int keycode, t_all *all);
void	you_win(t_all *all);

#endif