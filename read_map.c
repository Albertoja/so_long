#include "so_long.h"

char	**ft_read_map(void)
{
	int	fd;
	char	*str;
	int	mat_size;
	char **mat_map;
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	fd = open("maps/ber.ber", O_RDONLY);
	mat_size = ft_count_lines(fd);
	close(fd);
	fd = open("maps/ber.ber", O_RDONLY);
	str = get_next_line(fd);
	mat_map = (char **)malloc(sizeof(char *) * (mat_size + 1));
	mat_map[mat_size] = NULL;
	while (str)
	{
		mat_map[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
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
	close(fd);
	ft_check_map(mat_map, mat_size);
	return(mat_map);



}
