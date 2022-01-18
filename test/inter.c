#include <unistd.h>

int	main(int arguments, char **inter)
{
	int i;
	int j;
	int flag[256];

	if (arguments == 3)
	{
		i = 0;
		while (i < 256)
		{
			flag[i] = 0;
			i++;
		}
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (inter[i][j])
			{
				if (i == 2)
					flag[(int)inter[i][j]] = 1;
				else if ((i == 1) && flag[(int)inter[i][j]] == 1)
				{
					flag[(int)inter[i][j]] = 2;
					write(1, &inter[i][j], 1);
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}