#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fPointer;
	fPointer = fopen("text.txt", "r");
	char singleLine[150];

	while(!feof(fPointer))
	{
		fgets(singleLine, 150, fPointer);
		puts(singleLine);
	}
	fclose(fPointer);

	return 0;
}