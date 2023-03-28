<<<<<<< HEAD
#include "main.h"

void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * run_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1,
					&tmp);
			len = handle_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);

	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}
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
