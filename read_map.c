#include "so_long.h"
void	ft_check_map(char *str)
{
	static size_t len;
	static int exist_C;
	static int exist_P;
	static int exist_E;
	int	cont;

	cont = 0;
	if(!len)
		len = ft_strlen(str);
	else
		{
			if(len != ft_strlen(str))
			{
				write(2, "ERROR -> sizemap\n", 17);
				free(str);
				exit(0);
			}
		}
	while(str[cont])
	{
		if(str[cont] == 'C')
			exist_C++;
		if(str[cont] == 'P')
			exist_P++;
		if(str[cont] == 'E')
			exist_E++;
		if(str[cont] != '0' && str[cont]  != 'C' && str[cont] != 'P' && str[cont] != 'E' && str[cont] != '1' && str[cont] != '\n')
		{
			write(2, "ERROR -> ", 9);
			write(2, &str[cont], 1);
			write(2, " -> is not a valid character for the map", 37);
			write(2, "\n", 1);
			free(str);
			exit(0);
		}
		cont++;
	}
	if(str[0] != '1' || str[len - 2] != '1')
	{
		write(2, "ERROR -> the map is not closed\n", 31);
		free(str);
		exit(0);
	}
}
void	ft_read_map(void)
{
	int	fd;
	char	*str;
	int	mat_size;
	char **mat_map;
	int cont;
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	cont = 0;
	fd = open("maps/.ber.ber", O_RDONLY);
	mat_size = ft_count_lines(fd);
	fd = open("maps/.ber.ber", O_RDONLY);
	str = get_next_line(fd);
	mat_map = (char **)malloc(sizeof(char *) * (mat_size + 1));
	while (str)
	{
		mat_map[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		//ft_check_map(str);
		while(str[a])
			mat_map[i][j++] = str[a++];
		mat_map[i][j] = '\0';
		free(str);
		str = get_next_line(fd);
		i++;
	}
	//write(1, &mat_map[0][0], 1);
	printf("%s", mat_map[1]);



}