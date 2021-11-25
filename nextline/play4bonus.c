#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("numbers.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	int i = 1;
	char *line = get_next_line(fd);
	/*printf("cancion:%s.\n", line);
	ifree(&line);
	printf("--------\n");
	line = get_next_line(fd);
	printf("%s.\n", line);
	ifree(&line);*/
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
	system("leaks numbers.out");
	return (0);
}