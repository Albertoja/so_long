/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:42 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/06 16:47:07 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy3(t_all *all, int i, int j)
{
	while (i < all->map.x - 2)
	{
		j = 1;
		while (j < all->map.y)
		{
			if (all->map.map[i][j] == 'v' && all->map.map[i - 1][j] == '0')
			{
				all->map.map[i][j] = '0';
				all->map.map[i - 1][j] = 'v';
			}
			else if (all->map.map[i][j] == 'v' && all->map.map[i - 1][j] == 'P')
				you_lose(all);
			else if (all->map.map[i][j] == 'v' && all->map.map[i - 1][j] == '1')
				all->map.map[i][j] = 'V';
		j++;
		}
		i++;
	}
}

void	move_enemy2(t_all *all, int i, int j)
{
	while (i > 0)
	{
		j = all->map.y - 2;
		while (j > 0)
		{
			if (all->map.map[i][j] == 'V')
			{
				if (all->map.map[i + 1][j] == '0')
				{
					all->map.map[i][j] = '0';
					all->map.map[i + 1][j] = 'V';
				}
				else if (all->map.map[i + 1][j] == 'P')
					you_lose(all);
				else if (all->map.map[i + 1][j] != '0')
					all->map.map[i][j] = 'v';
			}
			j--;
		}
		i--;
	}
}

void	move_enemy(t_all *all)
{
	int	i;
	int	j;
	int	cont;

	cont = 0;
	i = all->map.x - 3;
	j = all->map.y - 2;
	move_enemy2(all, i, j);
	i = 0;
	j = 0;
	move_enemy3(all, i, j);
}

void	spawn_enemy(t_all *all)
{
	int	x;
	int	y;
	int	aux;

	x = 1;
	y = 1;
	aux = 0;
	while (x < all->map.y)
	{
		if (all->map.map[y][x] == '0' && all->map.map[y + 1][x] == '0'
			&& all->map.map[y][x + 1] == '0' && all->map.map[y][x - 1] != 'V'
				&& all->map.map[y + 2][x] == '0')
			all->map.map[y][x] = 'V';
		x++;
	}
}
