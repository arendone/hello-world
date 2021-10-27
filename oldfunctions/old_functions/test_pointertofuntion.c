#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a, int b)
{
    printf("Value of a*b is %d\n", a*b);
}
  
int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int, int) = &fun;
  
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
  
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10, 5);
  
    return 0;
}