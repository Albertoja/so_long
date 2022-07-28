#include <mlx.h>
#include "so_long.h"

void	press_up(t_all *all)
{
	write(1, "arriba\n", 7);
	if (all->map.map[(all->player.y) - 1][all->player.x] == '1')
		return ;
	else
		{
			if (all->map.map[all->player.y - 1][all->player.x] == 'E')
			{
				if(all->col == 0)
					you_win(all);
				else
					return ;
			}
			if (all->map.map[all->player.y - 1][all->player.x] == 'C')
				all->col--;
			all->map.map[all->player.y][all->player.x] = '0';
			all->player.y = all->player.y - 1;
			all->map.map[all->player.y][all->player.x] = 'P';
		}
}
void	press_down(t_all *all)
{
	write(1, "abajo\n", 6);
	if (all->map.map[(all->player.y) + 1][all->player.x] == '1')
		return ;
	else
		{
			if (all->map.map[all->player.y + 1][all->player.x] == 'E')
			{
				if(all->col == 0)
					you_win(all);
				else
					return ;
			}
			if (all->map.map[all->player.y + 1][all->player.x] == 'C')
				all->col--;
			all->map.map[all->player.y][all->player.x] = '0';
			all->player.y = all->player.y + 1;
			all->map.map[all->player.y][all->player.x] = 'P';
		}
}
void	press_left(t_all *all)
{
	write(1, "izquierda\n", 10);
	if (all->map.map[all->player.y][all->player.x - 1] == '1')
		return ;
	else
		{
			if (all->map.map[all->player.y][all->player.x - 1] == 'E')
			{
				if(all->col == 0)
					you_win(all);
				else
					return ;
			}
			if (all->map.map[all->player.y][all->player.x - 1] == 'C')
				all->col--;
			all->map.map[all->player.y][all->player.x] = '0';
			all->player.x = all->player.x - 1;
			all->map.map[all->player.y][all->player.x] = 'P';
		}
}
void	press_right(t_all *all)
{
	write(1, "derecha\n", 8);
	if (all->map.map[all->player.y][all->player.x + 1] == '1')
		return ;
	else
		{
			if (all->map.map[all->player.y][all->player.x + 1] == 'E')
			{
				if(all->col == 0)
					you_win(all);
				else
					return ;
			}
			if (all->map.map[all->player.y][all->player.x + 1] == 'C')
				all->col++;
			all->map.map[all->player.y][all->player.x] = '0';
			all->player.x = all->player.x + 1;
			all->map.map[all->player.y][all->player.x] = 'P';
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
	ft_print_matrix(all);
	return (0);
}