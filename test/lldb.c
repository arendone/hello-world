#include <stdio.h>

int main()
{
	int one, two, sum;
	printf("enter two numbers: \n");
	scanf("%d %d", &one, &two);
	sum = one * two;
	printf("La suma de %d + %d es %d\n", one, two, sum);
	return 0;
}