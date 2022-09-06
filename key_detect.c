/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:15 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/01 16:47:56 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	press_up(t_all *all)
{
	if (all->map.map[(all->player.y) - 1][all->player.x] == '1')
		return ;
	else
	{
		if (all->map.map[all->player.y - 1][all->player.x] == 'E')
		{
			if (all->col == 0)
				you_win(all);
			else
				return ;
		}
		else
			all->movements++;
		if (all->map.map[all->player.y - 1][all->player.x] == 'C')
			all->col--;
		if (all->map.map[all->player.y - 1][all->player.x] == 'V'
			|| all->map.map[all->player.y - 1][all->player.x] == 'v')
			you_lose(all);
		all->map.map[all->player.y][all->player.x] = '0';
		all->player.y = all->player.y - 1;
		all->map.map[all->player.y][all->player.x] = 'P';
		ft_putnbr_fd(all->movements, 1);
		write(1, "\n", 1);
	}
}

void	press_down(t_all *all)
{
	if (all->map.map[(all->player.y) + 1][all->player.x] == '1')
		return ;
	else
	{
		if (all->map.map[all->player.y + 1][all->player.x] == 'E')
		{
			if (all->col == 0)
				you_win(all);
			else
				return ;
		}
		else
			all->movements++;
		if (all->map.map[all->player.y + 1][all->player.x] == 'C')
			all->col--;
		if (all->map.map[all->player.y + 1][all->player.x] == 'V'
			|| all->map.map[all->player.y + 1][all->player.x] == 'v')
			you_lose(all);
		all->map.map[all->player.y][all->player.x] = '0';
		all->player.y = all->player.y + 1;
		all->map.map[all->player.y][all->player.x] = 'P';
		ft_putnbr_fd(all->movements, 1);
		write(1, "\n", 1);
	}
}

void	press_left(t_all *all)
{
	if (all->map.map[all->player.y][all->player.x - 1] == '1')
		return ;
	else
	{
		if (all->map.map[all->player.y][all->player.x - 1] == 'E')
		{
			if (all->col == 0)
				you_win(all);
			else
				return ;
		}
		else
			all->movements++;
		if (all->map.map[all->player.y][all->player.x - 1] == 'C')
			all->col--;
		if (all->map.map[all->player.y][all->player.x - 1] == 'V'
			|| all->map.map[all->player.y][all->player.x - 1] == 'v')
			you_lose(all);
		all->map.map[all->player.y][all->player.x] = '0';
		all->player.x = all->player.x - 1;
		all->map.map[all->player.y][all->player.x] = 'P';
		ft_putnbr_fd(all->movements, 1);
		write(1, "\n", 1);
	}
}

void	press_right(t_all *all)
{
	if (all->map.map[all->player.y][all->player.x + 1] == '1')
		return ;
	else
	{
		if (all->map.map[all->player.y][all->player.x + 1] == 'E')
		{
			if (all->col == 0)
				you_win(all);
			else
				return ;
		}
		else
			all->movements++;
		if (all->map.map[all->player.y][all->player.x + 1] == 'C')
			all->col--;
		if (all->map.map[all->player.y][all->player.x + 1] == 'V'
			|| all->map.map[all->player.y][all->player.x + 1] == 'v')
			you_lose(all);
		all->map.map[all->player.y][all->player.x] = '0';
		all->player.x = all->player.x + 1;
		all->map.map[all->player.y][all->player.x] = 'P';
		ft_putnbr_fd(all->movements, 1);
		write(1, "\n", 1);
	}
}

int	key_detect(int keycode, t_all *all)
{
	if (keycode == 13)
		press_up(all);
	if (keycode == 1)
		press_down(all);
	if (keycode == 2)
		press_right(all);
	if (keycode == 0)
		press_left(all);
	if (keycode == 53)
		endwindow(all);
	return (0);
}
