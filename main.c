#include <mlx.h>
#include "so_long.h"

int	main(void)
{
	char **map;

	map = ft_read_map();
	ft_print_matrix(map);
	search_player(map);
}