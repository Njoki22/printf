#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_char(va_list arg);
void print_int(va_list arg);
void print_unsigned_int(va_list arg);
void print_octal(va_list arg);
void print_hexadecimal(va_list arg, int uppercase);
void print_pointer(va_list arg);
void print_string(va_list arg);
void print_percent(void);
void unknown_format_specifier(char specifier);

#endif /* MAIN_H */

