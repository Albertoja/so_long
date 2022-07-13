#include "so_long.h"

int ft_count_lines(int fd)
{
	int a;
	int ret;
	char *line;

	line = (char *)malloc(sizeof(char) * (1 + 1));
	ret = 0;
	a = 1;
	while (a == 1)
	{
		a = read(fd, line, 1);
		if (a == -1)
			return (0);
		if(!line)
			break;
		if (ft_strchr(line, '\n'))
			ret++;
	}
	free (line);
	return(ret + 1);
}