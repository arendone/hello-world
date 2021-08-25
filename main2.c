#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,65,7);
   puts(str);

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_memset(str,'$',7);
   puts(str);

   strcpy(str,"This is string.h library function");
   puts(str);

   bzero(str, 7);
   puts(str);

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_bzero(str, 7);
   puts(str);
 
   return(0);
}