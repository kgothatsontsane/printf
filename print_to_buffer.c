#include "main.h"

/**
 * print_to_buffer - Prints the buffer if it contains data
 * @buffer: Am array of characters
 * @buffer_index: The index at which to add next char
 */

void print_to_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
