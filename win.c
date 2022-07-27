#include "so_long.h"
#include <mlx.h>

void	you_win(t_all *all)
{
	write(1, "You win\n", 8);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
}