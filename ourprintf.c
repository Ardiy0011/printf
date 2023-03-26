#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include "main.c"

/**
 * _printf - enter point
 * Description: afunction that takes  variable number of function
 * @count: local variable within argument before indefinte variable
 * Return: Display
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
                    break;
            }
        } 
        else
        {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);

    return (count);
}
