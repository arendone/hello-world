
#include <stdio.h>

int main ()
{
	char s[12] = "aaa bbb ccc";

	//adress of the first a, b and c in s
	char *p1, *p2, *p3;
	p1 = &s[0];
	p2 = &s[4];
	p3 = &s[9];

	printf("ad1: %p, ad2: %p, ad3: %p\n", &s[0], &s[4], &s[9]);
	printf("ad1: %p, ad2: %p, ad3: %p\n", p1, p2, p3);


	//array with the adress of the 3 adresses
	char **array_p[3] = {&p1, &p2, &p3};

	//print the adress of the 3 adresses
	printf("ad1: %p, ad2: %p, ad3: %p\n", array_p[0], array_p[1], array_p[2]);

	//Print what is in the 3 adresses (the adress of the first a, b and c)
	printf("ad1: %p, ad2: %p, ad3: %p\n", *array_p[0], *array_p[1], *array_p[2]);

	return (0);
}
/*
int main ()
{
	char s[12] = "abc 123 def";
	char	array[3][5];
	char 	*parray[3];
	int i = 0;
	int j = 0;
	size_t k = 0;

	while (k < ft_strlen(s))
	{
		if (s[k] == ' ')
		{
			array[j][i] = s[k];
			j++;
			i = 0;
		}
		else
		{
			array[j][i] = s[k];
			if (i == 0)
				parray[j] = &array[j][0];
			i++;
		}
		k++;
	}
	
	printf("ad1: %s, ad2: %s, ad3: %s,\n", array[0], array[1], array[2]);
	printf("ad1: %p, ad2: %p, ad3: %p, final: %p \n", parray[0], parray[1], parray[2], parray);

	return (0);
} */