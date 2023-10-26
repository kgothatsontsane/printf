#include "main.h"

/**
 * write_num_to_buffer - Outputs a number using a character buffer
 * with specified formatting.
 * @index: The index at which the number starts in the buffer.
 * @buf: Array of characters to store the number and formatting.
 * @flgs: Flags specifying formatting.
 * @w: Width specifier.
 * @prec: Precision specifier
 * @len: The length of the number.
 * @padding: Padding character.
 * @extrac: Extra character to include, if any.
 *
 * Return: Writes a number using a character buffer with specified formatting.
 */
int write_num_to_buffer(int index, char buf[],
			int flgs, int w, int prec,
			int len, char padding, char extrac)
{
	int i, padding_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buf[index] == '0' && w == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buf[index] == '0')
		buf[index] = padding = ' ';
	if (prec > 0 && prec < len)
		padding = ' ';
	while (prec > len)
		buf[--index] = '0', len++;
	if (extrac != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			buf[i] = padding;
		buf[i] = '\0';
		if (flgs & F_MINUS && padding == ' ')
		{
			if (extrac)
				buf[--index] = extrac;
			return (write(1, &buf[index], len) +
				write(1, &buf[1], i - 1));
		}
		else if (!(flgs & F_MINUS) && padding == ' ')
		{
			if (extrac)
				buf[--index] = extrac;
			return (write(1, &buf[1], i - 1) +
				write(1, &buf[index], len));
		}
		else if (!(flgs & F_MINUS) && padding == '0')
		{
			if (extrac)
				buf[--padding_start] = extrac;
			return (write(1, &buf[padding_start],
				      i - padding_start) +
				write(1, &buf[index],
				      len - (1 - padding_start)));
		}
	}
	if (extrac)
		buf[--index] = extrac;
	return (write(1, &buf[index], len));
}
