#include <stdio.h>
#include <stdarg.h>

static FILE *pfile;

void	function1(void);

void	Write(FILE *stream, const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}

int main(void)
{
	pfile = fopen("my_vprintf.txt", "w");
	int var, var1;

	var = 1234;
	var1 = 5678;
	Write(pfile, "my debug info value of var is %d \n", 123);
	Write(pfile, "my debug info value of var1 is %d \n", var1);
	function1();
	fclose(pfile);
	return 0;
}

void function1(void)
{
	int fun_var = 3456;
	Write(pfile, "[%d]My debug info in function1 var %d \n", __LINE__, fun_var);
	Write(pfile, "[%d]My debug info in function1 var %d \n", 5, fun_var);
	Write(pfile, "[%d]My debug info in function1 var %d \n", __LINE__, fun_var);
	Write(pfile, "[%d]My debug info in function1 var %d \n", __LINE__, fun_var);
}