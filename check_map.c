#include "so_long.h"
void	ft_check_num_map(t_all *all)
{
	static int num_c;
	static int num_p;
	static int num_e;
	int			cont;
	int			cont_2;

	cont = 0;
	while(cont < all->map.x - 2)
	{
		cont_2 = 0;
		while(cont_2 < all->map.y)
		{
			// printf("cont %d\ncont2: %d\n", cont, cont_2);
			// ft_putchar_fd(all->map.map[cont][cont_2], 1);
			if(all->map.map[cont][cont_2] == 'C')
				num_c++;
			if(all->map.map[cont][cont_2] == 'P')
				num_p++;
			if(all->map.map[cont][cont_2] == 'E')
				num_e++;
			cont_2++;
		}
		cont++;

	}
	if(num_c < 1)
	{
		write(2, "ERROR -> invalid collectibles number\n", 37);
		//ft_free(all->map.map);
		exit(0);
	}
	if(num_p != 1)
	{
		write(2, "ERROR -> invalid player number\n", 31);
		//ft_free(all->map.map);
		exit(0);
	}
	if(num_e != 1)
	{
		write(2, "ERROR -> invalid exit number\n", 29);
		//ft_free(all->map.map);
		exit(0);
	}
}
void	ft_check_char_map(t_all *all)
{
	int	cont;
	int cont_2;
	int	size;


	//mat_size = mat_size - 2;
	cont = 0;
	size = ft_strlen(all->map.map[cont]);
	while(cont < all->map.x - 2)
	{
		cont_2 = 0;
		while(cont_2 < all->map.y - 1)
		{
			if(all->map.map[0][cont_2] != '1' || all->map.map[all->map.x - 3][cont_2] != '1' || all->map.map[cont][0] != '1' || all->map.map[cont][all->map.y - 2] != '1')
			{
				write(2, "ERROR -> the map is not closed\n", 31);
				//ft_free(all->map.map);
				exit(0);
			}
			else if(all->map.map[cont][cont_2] != '0' && all->map.map[cont][cont_2]  != 'C' && all->map.map[cont][cont_2] != 'P' && all->map.map[cont][cont_2] != 'E' && all->map.map[cont][cont_2] != '1' && all->map.map[cont][cont_2] != '\n' &&all->map.map[cont][cont_2] != 'V')
			{
				write(2, "ERROR -> ", 9);
				write(2, &all->map.map[cont][cont_2], 1);
				write(2, " -> is not a valid character for the map", 37);
				write(2, "\n", 1);
				//ft_free(all->map.map);
				exit(0);
			}
			cont_2++;
		}
		cont++;
	}
}

void	ft_check_map(t_all *all)
{
	//ft_check_size_map(all->map.map);

	ft_check_num_map(all);
	ft_check_char_map(all);
}

