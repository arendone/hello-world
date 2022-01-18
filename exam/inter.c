/*Write a program that takes two strings and displays, without doubles, 
the characters that appear in both strings, in the order they appear 
in the first one. The display will be followed by a \n. If the number 
of arguments is not 2, the program displays \n.*/

#include "unistd.h"

int main(int arg, char **str)
{
	int i, j;
	int flag[256];

	if (arg==3)
	{
		i = 0;
		while(i<256)
		{
			flag[i] = 0;
			i++;
		}
		i = 1;
		while(i < 3)
		{
			j = 0;
			while(str[i][j])
			{
				if (i == 1)
				{
					flag[(int)str[i][j]] = 1;
				}
				if (i == 2 && flag[(int)str[i][j]] == 1)
				{
					write(1, &str[i][j], 1);
					flag[(int)str[i][j]] = 2;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}