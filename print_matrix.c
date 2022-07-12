#include "so_long.h"
void	ft_print_matrix(char **mat)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while(mat[i])
	{
		j = 0;
		while(mat[i][j])
		{
			write(1, &mat[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	} 
}