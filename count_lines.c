/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:09 by aespinos          #+#    #+#             */
/*   Updated: 2022/09/01 16:39:20 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(int fd)
{
	int		a;
	int		ret;
	char	*line;

	line = (char *)malloc(sizeof(char) * (1 + 1));
	ret = 0;
	a = 1;
	while (a == 1)
	{
		a = read(fd, line, 1);
		line[1] = 0;
		if (a == -1)
			return (0);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			ret++;
	}
	if (line)
		free(line);
	return (ret + 1);
}
