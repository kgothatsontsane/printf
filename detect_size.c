#include "main.h"

/**
 * detect_size - Determines the data type casting size based on formattd_string
 * @formatted_string: The formatted string specifying how to print arguments.
 * @index: A reference to the current position within the format string.
 *
 * Return: Precision.
 */
int detect_size(const char *formatted_string, int *index)
{
	int currentPosition = *index + 1;
	int size = 0;

	if (formatted_string[currentPosition] == 'l')
		size = S_LONG;
	else if (formatted_string[currentPosition] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = currentPosition - 1;
	else
		*index = currentPosition;

	return (size);
}
