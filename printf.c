#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function that handles several instances of format specifiers in diffirent cases
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;

			switch (format[i])
			{
				case 'c':
					printed = handle_char(list, buffer, flags, width);
					break;
				case 's':
					printed = handle_string(list, buffer, flags, width, precision);
					break;
				case 'd':
				case 'i':
					printed = handle_integer(list, buffer, flags, width, precision);
					break;
				case 'u':
					printed = handle_unsigned_integer(list, buffer, flags, width, precision);
					break;
				case 'o':
					printed = handle_octal(list, buffer, flags, width, precision);
					break;
				case 'x':
				case 'X':
					printed = handle_hexadecimal(list, buffer, flags, width, precision, format[i]);
					break;
				case 'p':
					printed = handle_pointer(list, buffer, flags, width);
					break;
				case '%':
					printed = handle_percent(buffer, flags, width);
					break;
				default:
					printed = handle_invalid(format[i], buffer);
			}

			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

