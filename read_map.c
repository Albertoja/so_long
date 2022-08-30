#include "so_long.h"

void	ft_read_map(t_all *all, char **argv)
{
	int	fd;
	char	*str;
	int	mat_size;
	int	i;
	int	j;
	int	a;
	size_t	size;

	a = 0;
	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	mat_size = ft_count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	all->map.x = mat_size;
	str = get_next_line(fd);
	size = ft_strlen(str);
	all->map.map = (char **)malloc(sizeof(char *) * (mat_size + 1));
	all->map.map[mat_size] = NULL;
	all->map.y = ft_strlen(str);
	while (str)
	{
		if (size != ft_strlen(str))
			exit(0);
		size = ft_strlen(str);
		all->map.map[i] = (char *)malloc(sizeof(char) * (all->map.y));
		while(str[a] && str[a] != '\n')
		{
			all->map.map[i][j++] = str[a++];
		}
		all->map.map[i][j] = '\0';
		free(str);
		str = get_next_line(fd);
		a = 0;
		j = 0;
		i++;
	}
	if (str)
		free(str);
	close(fd);
	if (all->map.x * 64 > 5120 || all->map.y * 64 > 2880)
		exit(0);
	ft_check_map(all);
	return ;



}
