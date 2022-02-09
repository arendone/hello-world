
#include <unistd.h>

int main(void)
{
	char a = 'a';
	write(1, &a, 1);
	write(1, "\n", 1);
	a |= (1<<1);
	write(1, &a, 1);
	write(1, "\n", 1);
	a |= (1<<1);
	write(1, &a, 1);
	write(1, "\n", 1);
}