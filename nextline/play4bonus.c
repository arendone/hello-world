#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

//gcc -Wall -Wextra -Werror play4bonus.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=6 -o letra.out
//gcc -Wall -Wextra -Werror play4bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=6 -o letra.out

//MAIN WITHOUT BONUS
/*int	main(void)
{
	int	fd = open("text2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	int i = 1;
	char *line = get_next_line(fd);
	while (line)
	{
		if (line)
		{
			printf("fd(%d) #%d | %s", fd, i, line);
			ifree(&line);
			line = get_next_line(fd);
			if (!line)
			printf("\n");
		}
		i++;
	}
	system("leaks letra.out");
	return (0);
}*/

//MAIN WITH BONUS
int	main(void)
{
	int	fd = open("text2.txt", O_RDONLY);
	int	fd2 = open("text2.txt", O_RDONLY);
	if (fd == -1 || fd2== -1)
	{
		printf("open() error");
		return (1);
	}
	int i = 1;
	char *line = get_next_line(fd);
	char *line2 = get_next_line(fd2);
	while (line || line2)
	{
		if (line)
		{
			printf("fd(%d) #%d | %s", fd, i, line);
			ifree(&line);
			line = get_next_line(fd);
			if (!line)
			printf("\n");
		}
		if (line2)
		{
			printf("fd(%d) #%d | %s", fd2, i, line2);
			ifree(&line2);
			line2 = get_next_line(fd2);
			if (!line2)
			printf("\n");
		}
		i++;
	}
	system("leaks letra.out");
	return (0);
}
