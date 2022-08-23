#include "so_long.h"

void	ft_loadtilesimg2(t_all *all, int w, int h)
{
	all->images.mario = mlx_new_image(all->vars.mlx, SZEIMG, SZEIMG);
	all->images.mario = mlx_xpm_file_to_image(all->vars.mlx, \
	"./img/mariobros.xpm", &w, &h);
	// all->images.mario2 = mlx_new_image(all->vars.mlx, SZEIMG, SZEIMG);
	// all->images.mario2 = mlx_xpm_file_to_image(all->vars.mlx, \
	// "./img/Mario.xpm", &w, &h);
}

void	ft_loadtilesimg(t_all *all)
{
	int		w;
	int		h;

	all->images.floor = mlx_new_image(all->vars.mlx, SZEIMG, SZEIMG);
	all->images.floor = mlx_xpm_file_to_image(all->vars.mlx, \
	"./img/suelo.xpm", &w, &h);
	all->images.wallup = mlx_new_image(all->vars.mlx, SZEIMG, SZEIMG);
	all->images.wallup = mlx_xpm_file_to_image(all->vars.mlx, \
	"./img/pared.xpm", &w, &h);
	all->images.coll = mlx_new_image(all->vars.mlx, SZEIMG, SZEIMG);
	all->images.coll = mlx_xpm_file_to_image(all->vars.mlx, \
	"./img/coleccionable.xpm", &w, &h);
	all->images.exit = mlx_new_image(all->vars.mlx, SZEIMG, SZEIMG);
	all->images.exit = mlx_xpm_file_to_image(all->vars.mlx, \
	"./img/exit.xpm", &w, &h);
	ft_loadtilesimg2(all, w, h);
}

void	ft_printmap2(t_all *all)
{
	int x;
	int y;
	int	x_max;
	int	y_max;

	x_max = all->map.x;
	y_max = all->map.y;
	x = 0;
	y = 0;

	while(y < all->map.x)
	{
		while (x < all->map.y)
		{
			if (all->map.map[y][x] == '0')
				mlx_put_image_to_window(all->vars.mlx, all->vars.win, \
				all->images.floor, SZEIMG * x, SZEIMG * y);
			else if (all->map.map[y][x] == '1')
				mlx_put_image_to_window(all->vars.mlx, all->vars.win, \
				all->images.wallup, SZEIMG * x, SZEIMG * y);
			else if (all->map.map[y][x] == 'C')
				mlx_put_image_to_window(all->vars.mlx, all->vars.win, \
				all->images.coll, SZEIMG * x, SZEIMG * y);
			else if (all->map.map[y][x] == 'P')
				mlx_put_image_to_window(all->vars.mlx, all->vars.win, \
				all->images.mario, SZEIMG * x, SZEIMG * y);
			else if (all->map.map[y][x] == 'E')
				mlx_put_image_to_window(all->vars.mlx, all->vars.win, \
				all->images.exit, SZEIMG * x, SZEIMG * y);
			// else if (all->map.map[y][x] == 'P')
			// 	ft_printplayer(all);
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	y = 0;
}

int	ft_printmap(t_all *all)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	ft_printmap2(all);
	return (0);
}