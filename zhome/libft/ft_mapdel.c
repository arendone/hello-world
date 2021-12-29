#include "libft.h"

void	ft_mapdel(char **map, int i)
{
	if (map == NULL || i < 1)
		return ;
	while (i) //yo creo que lo correcto es i>=0
	{
		free(map[i]);
		i--;
	}
	free(map);
    //map = NULL; creo que esto falta
}