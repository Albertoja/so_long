#include "so_long.h"

void	print_first(t_all *all)
{
	int x;
	int y;
	int cont_x;
	int	cont_y;

	x = all->map.x;
	y = all->map.y;
	cont_x = 0;
	cont_y = 0;
	while(cont_y <= y)
	{
		while(cont_x <= x)
		{
			mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->images.mario,(all.map.map[cont_y][cont_x] * all->images.px), (all.map.map[cont_y][cont_x].row * all->images.px));
		}
	}
}