/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:05 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/01 16:36:50 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_closed(t_all *all, int cont, int cont_2)
{
	if (all->map.map[0][cont_2] != '1'
		|| all->map.map[all->map.x - 3][cont_2] != '1'
			|| all->map.map[cont][0] != '1'
				|| all->map.map[cont][all->map.y - 2] != '1')
	{
		write(2, "ERROR -> the map is not closed\n", 31);
		exit(0);
	}
	else if (all->map.map[cont][cont_2] != '0'
		&& all->map.map[cont][cont_2] != 'C'
			&& all->map.map[cont][cont_2] != 'P'
				&& all->map.map[cont][cont_2] != 'E'
					&& all->map.map[cont][cont_2] != '1'
						&& all->map.map[cont][cont_2] != '\n'
							&& all->map.map[cont][cont_2] != 'V')
	{
		write(2, "ERROR -> ", 9);
		write(2, &all->map.map[cont][cont_2], 1);
		write(2, " -> is not a valid character for the map", 40);
		write(2, "\n", 1);
		exit(0);
	}
}

void	ft_check_num_map2(int num_c, int num_p, int num_e)
{
	if (num_c < 1)
	{
		write(2, "ERROR -> invalid collectibles number\n", 37);
		exit(0);
	}
	if (num_p != 1)
	{
		write(2, "ERROR -> invalid player number\n", 31);
		exit(0);
	}
	if (num_e != 1)
	{
		write(2, "ERROR -> invalid exit number\n", 29);
		exit(0);
	}
}

void	ft_check_num_map(t_all *all)
{
	static int	num_c;
	static int	num_p;
	static int	num_e;
	int			cont;
	int			cont_2;

	cont = 0;
	while (cont < all->map.x - 2)
	{
		cont_2 = 0;
		while (cont_2 < all->map.y)
		{
			if (all->map.map[cont][cont_2] == 'C')
				num_c++;
			if (all->map.map[cont][cont_2] == 'P')
				num_p++;
			if (all->map.map[cont][cont_2] == 'E')
				num_e++;
			cont_2++;
		}
		cont++;
	}
	ft_check_num_map2(num_c, num_p, num_e);
}

void	ft_check_char_map(t_all *all)
{
	static int	cont;
	static int	cont_2;

	cont = 0;
	while (cont < all->map.x - 2)
	{
		cont_2 = 0;
		while (cont_2 < all->map.y - 1)
		{
			ft_check_closed(all, cont, cont_2);
			cont_2++;
		}
		cont++;
	}
}

void	ft_check_map(t_all *all)
{
	ft_check_num_map(all);
	ft_check_char_map(all);
}
