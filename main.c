#include <mlx.h>
#include "so_long.h"

int	endwindow(t_all *all)
{
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
	return (0);
}

void	images_init(t_all *all)
{
	all->images.px = 80;
	all->images.mario = mlx_xpm_file_to_image(all->vars.mlx,"./img/field.xpm", &all->images.px, &all->images.px);
}

int	main(void)
{
	t_all	all;
	int i;
	int	j;
	int	color;

	j = 0;
	i = 0;
	all.col = 0;
	all.vars.mlx = 0;
	all.vars.win = 0;
	all.map.map = 0;
	color = 0x00FF0000;
	
	all.map.map = ft_read_map(&all);
	images_init(&all);
	all.vars.mlx = mlx_init();
	all.vars.win = mlx_new_window(all.vars.mlx, all.map.y * 80, all.map.x * 80, "Hello world!");
	//write(1, "aqui\n", 5);
	ft_print_matrix(&all);
	search_player_col(&all);

	mlx_hook(all.vars.win, ON_DESTROY, 0L, endwindow, &all);
	mlx_key_hook(all.vars.win, key_detect, &all);
	//mlx_key_hook(vars.win, key_hook, &vars);
	//lx_loop_hook(mlx, render_next_frame, data);
	
	//mlx_put_image_to_window(all.vars.mlx, all.mlx_win, all.map.map, 0, 0);
	mlx_loop(all.vars.mlx);
}