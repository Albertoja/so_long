/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_player_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:35 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/06 16:41:39 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player_col(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	all->player.x = 0;
	all->player.y = 0;
	while (y < all->map.x - 2)
	{
		while (x < all->map.y)
		{
			if (all->map.map[y][x] == 'P')
			{
				all->player.x = x;
				all->player.y = y;
			}
			if (all->map.map[y][x] == 'C')
			{
				all->col = all->col + 1;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
