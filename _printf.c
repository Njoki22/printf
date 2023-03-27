#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
va_list args;
int i, count = 0;

va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
switch (format[++i])
{
case 'c':
_putchar(va_arg(args, int));
count++;
break;
case 's':
{
char *str = va_arg(args, char *);
while (*str != '\0')
{
_putchar(*str);
str++;
count++;
}
}
 break;
case '%':
_putchar('%');
count++;
break;
default:
_putchar('%');
_putchar(format[i]);
count += 2;
break;
}
}
else
{
_putchar(format[i]);
count++;
}
}

va_end(args);

return count;
}

