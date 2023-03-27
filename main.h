<<<<<<< HEAD
#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list R);

#endif  /* _MAIN_H */
=======
#ifndef HEADER_H
#define HEADER_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * struct printf_struct - structure
 * @p_str: pointer.
 * @f: variable.
 *
 * Description: array.
 */

typedef struct printf_struct
{
	char *p_str;
	int (*f)(va_list x);
} strct;

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list list);
int printf_str(va_list list);
int printf_porc(va_list list);
int printf_digit(va_list list);
int printf_reversed(va_list list);
int aux(int arg);
int (*get_function(char c))(va_list a);
#endif
>>>>>>> 0291f5358d114f0341ea3dcb2a134899a5dd6e4e
