#include "so_long.h"

t_player	*search_player(char **mat)
{
	t_player	*player;
	int	x;
	int y;
	y = 0;
	x = 0;
	while(mat[y])
	{
		while(mat[y][x])
		{
			if(mat[y][x] == 'P');
			{
				player->x = x;
				player->y = y;
			}
			x++;
		}
		y++;
		x = 0;
	}
	printf("%i\n", player->x);
	printf("%i\n", player->y);
	return(player);
}