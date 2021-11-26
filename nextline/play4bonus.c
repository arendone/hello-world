#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

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
	/*printf("cancion:%s.\n", line);
	ifree(&line);
	printf("--------\n");
	line = get_next_line(fd);
	printf("%s.\n", line);
	ifree(&line);*/
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