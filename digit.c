#include "main.h"

/**
 * digit - determines if a character is a digit or not
 * @d: character to be evaluated
 *
 * Return: 1 if c is a digit, 0 if it is not
 */
int digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}
