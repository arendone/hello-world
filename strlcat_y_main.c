#include <string.h>
#include <stdio.h>
#include <unistd.h>


int	ft_strlen(char *str)
{
	unsigned long int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    //char    *cdst;
    //char    *csrc;
    size_t  len_dst;
    int     i;

    //cdst = (char *)dst;
    //csrc = (char *)src; //Tal vez no los necesito
    len_dst = ft_strlen(dst);
    i = 0;
    while ((len_dst < size) && (src[i] != 0))
    {
        dst[len_dst] = src[i];
        len_dst++;
        i++;
    }
    dst[size] = '\0';
    return(len_dst);
}

int main(void)
{
    size_t  len_dst;
    char dst[20]="destino";
    char src[15]="concatenardoble";
    
    len_dst = ft_strlen(dst);
    printf("%s\n", dst);
    printf("len= %i \n", len_dst);
    ft_strlcat(dst, src, 20);
    len_dst = ft_strlen(dst);
    printf("%s\n", dst);
    printf("len= %i \n", len_dst);

    size_t  len2_dst;
    char dst2[20]="destino";
    char src2[12]="concaten";
    
    len2_dst = ft_strlen(dst);
    printf("%s\n", dst2);
    printf("len2= %i \n", len2_dst);
    ft_strlcat(dst2, src2, 20);
    len2_dst = ft_strlen(dst2);
    printf("%s\n", dst2);
    printf("len2= %i \n", len2_dst);
    return (0);
}