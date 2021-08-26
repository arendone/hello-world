#include <stdio.h>

char    *ft_strchr(const char *s, int c)//quite const char
{
    int i;
    char *p;

    p = (char *)s;
    i = 0;
    while (p[i] != '\0')
    {
        if (p[i] == c)
            break;
        i++;        
    }
    return (&p[i]);
}

int main(void)
{
    char s[20]="Hola";
    int c = 'B';
    char *p = ft_strchr(s, c);

    printf("%c:  %p, %c:  %p, %c:  %p, %c:  %p\n", s[0], &s[0], s[1], &s[1], s[2], &s[2], s[3], &s[3]);
    printf("%c en %p\n", &p, p);
    return (0);
}