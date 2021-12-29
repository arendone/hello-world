
#include <unistd.h>

int main(int arguments, char **uni)
{
	int i;
	int j;
	int flag[255];

	i = 0;
	if(arguments == 3)
	{
		while (i < 256)
		{
			flag[i] = 0;
			i++;
		}
		i = 1;
		while(i < 3)
		{
			j = 0;
			while (uni[i][j])
			{
				if (flag[(int)uni[i][j]] == 0)
				{
					flag[(int)uni[i][j]] = 1;
					write(1, &uni[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
