#include "so_long.h"
void	move_enemy(t_all *all)
{
	int i;
	int	j;
	int cont;

	cont = 0;
	i = (all->map.x) - 1;
	j = all->map.y;
	while(i > 0)
	{
		j = all->map.y;
		while(j > 0)
		{
			if (all->map.map[i][j] == 'V')
			{
				if(all->map.map[i + 1][j] == '0')
				{
					all->map.map[i][j] = '0';
					all->map.map[i + 1][j] = 'V';
				}
				else if (all->map.map[i + 1][j] == 'P')
					you_lose(all);
				else if(all->map.map[i + 1][j] != '0')
					all->map.map[i][j] = 'v';
			}
			j--;
		}
		i--;
	}
	i = 0;
	j = 0;
	while(i < all->map.x)
	{
		j = 1;
		while(j < all->map.y)
		{
			if(all->map.map[i][j] == 'v' && all->map.map[i - 1][j] == '0')
			{
				all->map.map[i][j] = '0';
				all->map.map[i - 1][j] = 'v';
			}
			else if (all->map.map[i][j] == 'v' && all->map.map[i - 1][j] == 'P')
				you_lose(all);
			else if(all->map.map[i][j] == 'v' && all->map.map[i - 1][j] == '1')
				all->map.map[i][j] = 'V';
		j++;
		}
		i++;
	}
}
void	spawn_enemy(t_all *all)
{
	int	x;
	int	y;
	int	aux;

	x = 1;
	y = 1;
	aux = 0;
	// while(y < all->map.x)
	// {
		while (x < all->map.y)
		{
			if(all->map.map[y][x] == '0' && all->map.map[y + 1][x] == '0' && all->map.map[y][x + 1] == '0' && all->map.map[y][x - 1] != 'V')
			{
				all->map.map[y][x] = 'V';
			}
			x++;
		}
		// aux++;
		// y++;
		// x = 0;
	//}
}