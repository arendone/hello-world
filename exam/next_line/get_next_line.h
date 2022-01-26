#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>		// [man 2 open]
# include <unistd.h>	// [man 2 read]
# include <stdio.h>		// [man 3 printf]
# include <stdlib.h>	// [man free]

char	*get_next_line(int fd);
#endif