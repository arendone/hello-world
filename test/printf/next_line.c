#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
​
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
​
int	my_search(char	*pot) //auch gucken obs nicht auch mal buf ist! ;)
{
	int	i;
​
	i = 0;
	if (pot == NULL)
		return (-1);
	while (pot[i] != '\0')
	{
		if (pot[i] == '\n')
			return (i);
		i++;
	}
	return (-1); //warum?? nochmla ge nau schauen wann bie den IFS die -1 verwendet wird!
}
​
int	my_len(char	*str)
{
	int	i;
​
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
​
char	*my_join(char *pot, char	*buf)
{
	int		i;
	int		len1;
	int		len2;
	char	*join;
​
	//deklarieren
​
	len1 = my_len(pot);
	len2 = my_len(buf);
​
	//längen
​
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return (NULL);
​
	//join alloc & check
​
	i = 0; //I!!!
​
	while (i < len1)
	{
		join[i] = pot[i];
		i++;
	}
​
	//erster teil
​
	i = 0; //I!!!
	while (i < len2)
	{
		join[len1 + i] = buf[i];
		i++;
	}
​
	// zweiter Teil
​
	join[len1 + len2] = '\0'; //null terminieren
​
	free (pot); //warum buf nicht, weil das noch für gnl gebraucht wird, und dort einfach uberschieben wird
	// pot muss egfreet werden weil der durch join auf was neues zeigt und sonst we ware
	return (join);
}
​
char	*my_subs(char	*pot, int start, int len)
{
	int		i;
	char	*subs;
​
	//deklarieren
​
	if (pot == NULL)
		return (NULL);
	
	//leerer topf
​
	if (start >= my_len(pot))//braucht man das?
		len = 0;
​
	//start > len
​
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	
	//subs malloc & check
​
	i = 0;
	while (i < len && pot[start + i] != '\0')
	{
		subs[i] = pot[start + i];
		i++;
	}
​
	//auffüllen
​
	subs[i] = '\0'; // null terminieren
	return (subs);
}
​
char	*output(char **pot)
{
	char	*tmp;
	char	*output;
	int		next;
​
	//deklarieren
​
	tmp = *pot; //pot umpflanzen
	if (my_search(*pot) > -1) //IF finden
	{
		next = my_search(*pot) + 1;
		output = my_subs(*pot, 0, next);
		*pot = my_subs(*pot, next, my_len(*pot) - next);
	}
​
	// ausgeben alle var
​
	else
	{
		output = my_subs(*pot, 0, my_len(*pot));
		*pot = NULL;
	}
​
	// ausgebn nur strings
	free(tmp);
	return (output);
}
​
char	*my_gnl(int fd)
{
	static char	*pot;
	char		*buf;
	int			bytes;
​
//deklarieren
​
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
​
//idioten input
​
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
​
//buf malloc und check
​
	bytes = 1;
	while (my_search(pot) == -1 && bytes > 0) // WHILE keine newline und nicht EOF
	{
		bytes = read(fd, buf, BUFFER_SIZE); //lesen
		if (bytes == -1 || (bytes == 0 && pot == NULL)) //IF lesen fehler || genau EOF und static ist auch leer
		{
			free(buf);
			free(pot);
			pot = NULL;
			return (NULL);
		}
​
		//freen
​
		buf[BUFFER_SIZE] = '\0'; //Nullterminante
		pot = my_join(pot, buf); //strjoin
	}
	if (pot == NULL || pot[0] == 0) //malloc protection u.a. || nullterminante an der stelle -> dann gibts nichts zum ausgeben
	{
		free(buf);
		free(pot);
		pot = NULL;
		return (NULL);
	}
​
	//freen
​
	free (buf); //free buf
	return (output(&pot)); //output call mit &
}
​
int	main(void)
{
	int		fd;
	int		lines;
	char	*gnl;
​
	fd = open("jorja.smith", O_RDONLY);
	// printf("%d <- fd \n", fd);
	lines = 0;
	while (lines < 10)
	{
		gnl = my_gnl(fd);
		printf("%s\n", gnl);
		lines++;
	}
	return (0);
}