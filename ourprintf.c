#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include "main.c"

/**
 * _printf - enter point
 * Description: afunction that takes  variable number of function
 * @display: local variable within argument before indefinte variable
 * Return: Display
 */
int _printf(const char *format, ...)
{
    va_list arg_list;
    int display = 0;
    const char *p;

    va_start(arg_list, format);

    for (p = format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            display++;
            }
            else
            {
                p++;
                switch (*p)
                {
                    case 'c':
                    {
                    char c = va_arg(arg_list, int);
                    putchar(c);
                    display++;
                    break;
                }
                case 's':
                {
                    const char *s = va_arg(arg_list, const char *);
                    display += printf("%s", s);
                    break;
                }
                case '%':
                {
                    putchar('%');
                    display++;
                    break;
                }
            }
        }
    }
    
    va_end(arg_list);
    
    give_us(display);
}
