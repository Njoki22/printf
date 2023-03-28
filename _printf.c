<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
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
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
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
<<<<<<< HEAD

=======
=======
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list arg;
    int done = 0;
    char buffer[256];
    int i, j;

    va_start(arg, format);

    for (i = 0, j = 0; format[i]; i++) {
        if (format[i] == '%') {
            buffer[j] = '\0';
            printf("%s", buffer);
            j = 0;

            switch (format[++i]) {
                case 'c':
                    print_char(arg);
                    break;

                case 'd':
                case 'i':
                    print_int(arg);
                    break;

                case 'u':
                    print_unsigned_int(arg);
                    break;

                case 'o':
                    print_octal(arg);
                    break;

                case 'x':
                    print_hexadecimal(arg, 0);
                    break;

                case 'X':
                    print_hexadecimal(arg, 1);
                    break;

                case 'p':
                    print_pointer(arg);
                    break;

                case 's':
                    print_string(arg);
                    break;

                case '%':
                    print_percent();
                    break;

                default:
                    unknown_format_specifier(format[i]);
                    break;
            }
        } else {
            buffer[j++] = format[i];
        }
    }

    buffer[j] = '\0';
    printf("%s", buffer);

    va_end(arg);
    return done;
}

void print_char(va_list arg) {
    printf("%c", va_arg(arg, int));
}

void print_int(va_list arg) {
    printf("%d", va_arg(arg, int));
}

void print_unsigned_int(va_list arg) {
    printf("%u", va_arg(arg, unsigned int));
}

void print_octal(va_list arg) {
    printf("%o", va_arg(arg, unsigned int));
}

void print_hexadecimal(va_list arg, int uppercase) {
    if (uppercase) {
        printf("%X", va_arg(arg, unsigned int));
    } else {
        printf("%x", va_arg(arg, unsigned int));
    }
}

void print_pointer(va_list arg) {
    printf("%p", va_arg(arg, void *));
}

void print_string(va_list arg) {
    printf("%s", va_arg(arg, char *));
}

void print_percent(void) {
    printf("%%");
}

void unknown_format_specifier(char specifier) {
    printf("%%%c", specifier);
}

>>>>>>> updated
>>>>>>> 67df1863355cfddf3d85aa7323cd6a40d28cb561
