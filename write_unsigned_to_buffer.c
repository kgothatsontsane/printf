#include "main.h"

/**
 * write_unsigned_to_buffer - Outputs an unsigned number with formatting.
 * @negative:A flag indicating if the number is negative
 * @index: The index at which the number starts in the buffer.
 * @buf: Array of characters to store the number and formatting.
 * @flgs: Flags specifying formatting.
 * @w: Width specifier.
 * @prec: Precision specifier
 * @sz: Size specifier an unsigned number with specified formatting.
 *
 * Return: Writes an unsigned number with specified formatting.
 */
int write_unsigned_to_buffer(int negative, int index,
				 char buf[],
				 int flgs, int w, int prec, int sz)
{
	int len = BUFF_SIZE - index - 1, i = 0;
	char padding = ' ';

	UNUSED(negative);
	UNUSED(sz);

	if (prec == 0 && index == BUFF_SIZE - 2 && buf[index] == '0')
		return (0);

	if (prec > 0 && prec < len)
		padding = ' ';

	while (prec > len)
	{
		buf[--index] = '0';
		len++;
	}

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padding = '0';

	if (w > len)
	{
		for (i = 0; i < w - len; i++)
			buf[i] = padding;

		buf[i] = '\0';

		if (flgs & F_MINUS)
		{
			return (write(1, &buf[index], len) +
				write(1, &buf[0], i));
		}
		else
		{
			return (write(1, &buf[0], i) +
				write(1, &buf[index], len));
		}
	}

	return (write(1, &buf[index], len));
}
