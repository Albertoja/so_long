#include <mlx.h>
#include "so_long.h"

int	endwindow(t_all *all)
{
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
	return (0);
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
	all.vars.mlx = mlx_init();
	all.vars.win = mlx_new_window(all.vars.mlx, 1920, 1080, "Hello world!");
	all.map.map = ft_read_map();
	//write(1, "aqui\n", 5);
	ft_print_matrix(&all);
	search_player_col(&all);
	//all.vars.win  = mlx_new_image(all.vars.mlx, 1920, 1080);
	// all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
	// 							&all.data.endian);
	mlx_hook(all.vars.win, ON_DESTROY, 0L, endwindow, &all);
	mlx_key_hook(all.vars.win, key_detect, &all);
	//mlx_key_hook(vars.win, key_hook, &vars);
	// while(j <= 1079)
	// {
	// 	my_mlx_pixel_put(&img, i, j, color);
	// 	if(i % 2 == 0)
	// 		color = 0x0000FF00;
	// 	else if(i % 2 != 0)
	// 		color = 0x0000FF00;
	// 	i++;
	// 	if(i == 1919)
	// 	{
	// 		i = 0;
	// 		j++;
	// 	}
	// }
	//lx_loop_hook(mlx, render_next_frame, data);
	
	//mlx_put_image_to_window(all.vars.mlx, all.mlx_win, all.map.map, 0, 0);
	mlx_loop(all.vars.mlx);
}