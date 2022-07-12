#include "so_long.h"
void	ft_check_map(char **str, int mat_size)
{
	static size_t len;
	int	cont;
	int cont_2;
	static int num_c;
	static int num_p;
	static int num_e;
	cont = 0;
	cont_2 = 0; 
	len = ft_strlen(str[cont]);
	while(str[cont])
	{
		if(ft_strlen(str[cont]) != len)
		{
			write(2, "ERROR -> sizemap\n", 17);
			//free(str);
			exit(0);
		}
		cont++;
	}
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
			if(str[0][cont_2] != '1' || str[mat_size - 1][cont_2] != '1' || str[cont][0] != '1' || str[cont][ft_strlen(str[cont])-1] != '1')
			{
				write(2, "ERROR -> the map is not closed\n", 31);
				//free(str);
				exit(0);
			}
			else if(str[cont][cont_2] != '0' && str[cont][cont_2]  != 'C' && str[cont][cont_2] != 'P' && str[cont][cont_2] != 'E' && str[cont][cont_2] != '1' && str[cont][cont_2] != '\n')
			{
				write(2, "ERROR -> ", 9);
				write(2, &str[cont][cont_2], 1);
				write(2, " -> is not a valid character for the map", 37);
				write(2, "\n", 1);
				//free(str);
				exit(0);
			}
			cont_2++;
		}
		cont++;
		cont_2 = 0;
	}
	if(num_c < 1)
	{
		write(2, "ERROR -> invalid collectibles number", 36);
		exit(0);
	}
	if(num_p != 1)
	{
		write(2, "ERROR -> invalid player number", 30);
		exit(0);
	}
	if(num_e != 1)
	{
		write(2, "ERROR -> invalid exit number", 28);
		exit(0);
	}
	
}
void	ft_read_map(void)
{
	int	fd;
	char	*str;
	int	mat_size;
	char **mat_map;
	//int cont;
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	fd = open("maps/ber.ber", O_RDONLY);
	mat_size = ft_count_lines(fd);
	fd = open("maps/ber.ber", O_RDONLY);
	str = get_next_line(fd);
	mat_map = (char **)malloc(sizeof(char *) * (mat_size + 1));
	while (str)
	{
		mat_map[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		//ft_check_map(str);
		//write(1, "hola\n", 5);
		while(str[a])
			mat_map[i][j++] = str[a++];
		if(mat_map[i][j - 1] == '\n')
			j--;
		mat_map[i][j] = '\0';
		free(str);
		str = get_next_line(fd);
		a = 0;
		j = 0;
		i++;
	}
	ft_check_map(mat_map, mat_size);
	ft_print_matrix(mat_map);
	//write(1, "\n", 1);
	//write(1, &mat_map[1][1], 1);
	//printf("%s", mat_map[1]);



}