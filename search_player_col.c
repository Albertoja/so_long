#include "so_long.h"

void	search_player_col(t_all *all)
{
	int	x;
	int y;
	char **mat;

	mat = all->map.map;
	y = 0;
	x = 0;
	//all->player = malloc(2);
	all->player.x = 0;
	all->player.y = 0;
	while(mat[y])
	{
		while(mat[y][x])
		{
			if(mat[y][x] == 'P')
			{
				all->player.x = x;
				all->player.y = y;
			}
			if(mat[y][x] == 'C')
			{
				all->col = all->col + 1;
			}
			x++;
		}
		y++;
		x = 0;
	}
	return	;
}
