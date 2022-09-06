/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:40 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/06 16:52:27 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <mlx.h>

typedef struct s_data {
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

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map {
	int		x;
	int		y;
	int		recx;
	int		recy;
	char	**map;
}	t_map;

typedef struct s_images {
	int		px;
	void	*mario;
	void	*mario2;
	void	*pablo;
	void	*pablo2;
	void	*floor;
	void	*wallup;
	void	*coll;
	void	*exit;

}	t_images;

typedef struct s_all{
	int			col;
	int			win;
	int			time;
	int			swframe;
	int			movements;
	t_player	player;
	t_data		data;
	t_vars		vars;
	t_map		map;
	t_images	images;
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

enum {
	SZEIMG = 64,
	MAXWIDTH = 5120,
	MAXHEIGHT = 2880
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*get_next_line(int fd);
void	ft_read_map(t_all *all, char **argv);
int		ft_count_lines(int fd);
void	ft_print_matrix(t_all *all);
void	ft_free(char **matrix);
void	ft_check_map(t_all *all);
char	*ft_strchr(const char *s, int c);
void	search_player_col(t_all *all);
int		key_hook(int keycode, t_vars *vars);
int		key_detect(int keycode, t_all *all);
void	you_win(t_all *all);
int		ft_printmap(t_all *all);
void	ft_loadtilesimg(t_all *all);
void	spawn_enemy(t_all *all);
void	move_enemy(t_all *all);
void	you_lose(t_all *all);
int		endwindow(t_all *all);
#endif
