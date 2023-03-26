#include <stdio.h>

int main()
{
    char c = 'A';
    char *s = "Hello, world!";

    printf("Testing _printf:\n");
    printf("_printf(\"%%c\", '%c')\n", c);
    _printf("%c\n", c);
    printf("_printf(\"%%s\", \"%s\")\n", s);
    _printf("%s\n", s);
    printf("_printf(\"%%%%\")\n");
    _printf("%%\n");
    printf("_printf(\"%%d\", 12345)\n");
    _printf("%d\n", 12345);

    return (0);
}
