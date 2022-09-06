/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:45 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/06 17:30:49 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	you_win(t_all *all)
{
	write(1, "You win\n", 8);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
}

void	you_lose(t_all *all)
{
	write(1, "You lose\n", 9);
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
}
