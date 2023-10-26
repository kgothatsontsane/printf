#include "main.h"

/**
 * write_char_to_buffer - Prints a for writing a character
 * @c: The character to be printed.
 * @buffer: Array to store the character and formatting.
 * @flags: Flags specifying formatting.
 * @w: Width specifier.
 * @prec: Precision specifier.
 * @sz: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_char_to_buffer(char c, char buffer[],
			 int flags, int w, int prec, int sz)
{
	/* char is stored at left and paddinng at buffer's right */
	int i = 0;
	char padding = ' ';

	UNUSED(prec);
	UNUSED(sz);

	if (flags & F_ZERO)
		padding = '0';

	buffer[i++] = c;
	buffer[i] = '\0';
	if (w > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padding;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], w - 1) +
				write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
