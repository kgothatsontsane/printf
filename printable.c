#include "main.h"

/**
 * printable - checks if a character is printable
 * @c: the character to be evaluated
 *
 * Return: 1 if 'c' is printable, 0 otherwise
 */

int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
