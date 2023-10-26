#include "main.h"

/**
 * determine_precision - Computes the precision value for printing.
 * @formatted_string: The formatted string specifying how to print arguments.
 * @index: A reference to the current position within the format string.
 * @a_list: The list of arguments.
 *
 * Return: The computed precision value.
 */
int determine_precision(const char *formatted_string, int *index,
			va_list a_list)
{
	int currentPosition = *index + 1;
	int precision = -1;

	if (formatted_string[currentPosition] != '.')
		return (precision);

	precision = 0;

	for (currentPosition += 1; formatted_string[currentPosition] != '\0';
	     currentPosition++)
	{
		if (digit(formatted_string[currentPosition]))
		{
			precision *= 10;
			precision += formatted_string[currentPosition] - '0';
		}
		else if (formatted_string[currentPosition] == '*')
		{
			currentPosition++;
			precision = va_arg(a_list, int);
			break;
		}
		else
			break;
	}

	*index = currentPosition - 1;

	return (precision);
}
