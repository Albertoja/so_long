#include <mlx.h>
#include "so_long.h"

int	endwindow(t_all *all)
{
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
	return (0);
}


int	main(int argc, char **argv)
{
	t_all	all;
	int i;
	int	j;

	j = 0;
	i = 0;
	all.col = 0;
	all.vars.mlx = 0;
	all.vars.win = 0;
	all.map.map = 0;
	all.time = 0;
	all.map.recx = 0;
	all.map.recy = 0;
	all.swframe = 0;
	all.map.x = 0;
	all.map.y = 0;
	all.movements = 0;

	if (argc != 2)
		exit(0);
	
	ft_read_map(&all, argv);
	all.vars.mlx = mlx_init();
	ft_loadtilesimg(&all);
	all.vars.win = mlx_new_window(all.vars.mlx, (all.map.y - 1) * 64, (all.map.x - 2) * 64, "Hello world!");
	search_player_col(&all);
	spawn_enemy(&all);
	ft_printmap(&all);
	mlx_hook(all.vars.win, ON_DESTROY, 0L, endwindow, &all);
	mlx_key_hook(all.vars.win, key_detect, &all);
	mlx_loop_hook(all.vars.mlx, ft_printmap, &all);
	mlx_loop(all.vars.mlx);
}
