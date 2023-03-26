#include <stdarg.h>
#include <stdio.h>

int main(void)
{
    int display;

    /*Test with a single character */
    display = _printf("a\n");
  

    /* Test with a string*/
    display = _printf("Getting the hang of C!\n");
   

    /* Test with a character and a string*/
    display = _printf("The first letter of the alphabet is %c, followed by %s.\n", 'a', "b");
 

    /* Test with a percent symbol*/
    display = _printf("100%%\n");

    return (0);
}
