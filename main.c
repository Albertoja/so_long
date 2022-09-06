/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:18 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/06 17:42:06 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	endwindow(t_all *all)
{
	ft_free(all->map.map);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;
	int		i;
	int		j;

	all.col = 0;
	all.time = 0;
	all.swframe = 0;
	all.movements = 0;
	if (argc != 2)
		exit(0);
	ft_read_map(&all, argv);
	all.vars.mlx = mlx_init();
	ft_loadtilesimg(&all);
	i = (all.map.y - 1) * 64;
	j = (all.map.x - 2) * 64;
	all.vars.win = mlx_new_window(all.vars.mlx, i, j, "so_long");
	search_player_col(&all);
	spawn_enemy(&all);
	ft_printmap(&all);
	mlx_hook(all.vars.win, ON_DESTROY, 0L, endwindow, &all);
	mlx_key_hook(all.vars.win, key_detect, &all);
	mlx_loop_hook(all.vars.mlx, ft_printmap, &all);
	mlx_loop(all.vars.mlx);
}
