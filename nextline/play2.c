#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 #include <fcntl.h>

// gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=12

void ifree(char **str)
{
    if (*str)
        free(*str);
    *str =NULL;
}

char *get_next_line(int fd)
{
    char *buf;
    buf = (char *)malloc(12);
    read(fd, buf, 11);
    buf [11] = '\0';
    return (buf);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	int i = 1;
	char *line = get_next_line(fd);
	while (line)
	{
		if (line)
		{
			printf("fd(%d) #%d:	%s.", fd, i, line);
			ifree(&line);
			//line = get_next_line(fd);
			//if (!line)
				printf("\n");
		}
		i++;
	}
	return (0);
}