#include "so_long.h"
void	ft_check_num_map(char **str)
{
	static int num_c;
	static int num_p;
	static int num_e;
	int			cont;
	int			cont_2;
	cont = 0;
	cont_2 = 0;
	while(str[cont])
	{
		while(str[cont][cont_2])
		{
			if(str[cont][cont_2] == 'C')
				num_c++;
			if(str[cont][cont_2] == 'P')
				num_p++;
			if(str[cont][cont_2] == 'E')
				num_e++;
			cont_2++;
		}
		cont++;
		cont_2 = 0;
	}

	if(num_c < 1)
	{
		write(2, "ERROR -> invalid collectibles number\n", 37);
		ft_free(str);
		exit(0);
	}
	if(num_p != 1)
	{
		write(2, "ERROR -> invalid player number\n", 31);
		ft_free(str);
		exit(0);
	}
	if(num_e != 1)
	{
		write(2, "ERROR -> invalid exit number\n", 29);
		ft_free(str);
		exit(0);
	}
}
void	ft_check_char_map(char **str, int mat_size)
{
	int	cont;
	int cont_2;

	cont = 0;
	cont_2 = 0;
	while(str[cont])
	{
		while(str[cont][cont_2])
		{
			if(str[0][cont_2] != '1' || str[mat_size - 1][cont_2] != '1' || str[cont][0] != '1' || str[cont][ft_strlen(str[cont])-1] != '1')
			{
				write(2, "ERROR -> the map is not closed\n", 31);
				ft_free(str);
				exit(0);
			}
			else if(str[cont][cont_2] != '0' && str[cont][cont_2]  != 'C' && str[cont][cont_2] != 'P' && str[cont][cont_2] != 'E' && str[cont][cont_2] != '1' && str[cont][cont_2] != '\n')
			{
				write(2, "ERROR -> ", 9);
				write(2, &str[cont][cont_2], 1);
				write(2, " -> is not a valid character for the map", 37);
				write(2, "\n", 1);
				ft_free(str);
				exit(0);
			}
			cont_2++;
		}
		cont++;
		cont_2 = 0;
	}
}
void	ft_check_size_map(char **str)
{
	int	cont;
	size_t len;

	cont = 0;
	len = ft_strlen(str[cont]);
	while(str[cont])
	{
		if(ft_strlen(str[cont]) != len)
		{
			write(2, "ERROR -> sizemap\n", 17);
			ft_free(str);
			exit(0);
		}
		cont++;
	}
}

void	ft_check_map(char **str, int mat_size)
{
	ft_check_size_map(str);
	ft_check_char_map(str, mat_size);
	ft_check_num_map(str);
	
}