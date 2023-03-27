#include <unistd.h>
<<<<<<< HEAD

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
=======
/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
>>>>>>> 0291f5358d114f0341ea3dcb2a134899a5dd6e4e
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
