/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:33 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/06 16:39:14 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_size(size_t size, char *str)
{
	if (size != ft_strlen(str))
	{
		if (str)
			free(str);
		write(2, "Error: no square map\n", 21);
		exit(0);
	}
}

void	ft_read_map2(t_all *all, char *str, int fd)
{
	size_t		size;
	static int	i;
	static int	j;
	static int	a;

	size = ft_strlen(str);
	if (!size)
		exit(0);
	while (str)
	{
		check_size(size, str);
		size = ft_strlen(str);
		all->map.map[i] = (char *)malloc(sizeof(char) * (all->map.y));
		while (str[a] && str[a] != '\n')
			all->map.map[i][j++] = str[a++];
		all->map.map[i][j] = '\0';
		free(str);
		str = get_next_line(fd);
		a = 0;
		j = 0;
		i++;
	}
	if (str)
		free(str);
}

void	error_norm(char a)
{
	if (a == 'e')
		write(2, "Error: empty\n", 13);
	if (a == 'b')
		write(2, "Error: too big!\n", 16);
	exit(0);
}

void	ft_read_map(t_all *all, char **argv)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	all->map.x = ft_count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		error_norm('e');
	all->map.map = (char **)malloc(sizeof(char *) * (all->map.x + 1));
	all->map.map[all->map.x] = NULL;
	all->map.y = ft_strlen(str);
	ft_read_map2(all, str, fd);
	close(fd);
	if (all->map.x * 64 > 5120 || all->map.y * 64 > 2880)
		error_norm('b');
	ft_check_map(all);
}
