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

