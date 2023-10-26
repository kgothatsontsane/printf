#include "main.h"

/**
 * write_pointer_to_buffer - Outputs a memory address to a
 * character buffer with formatting.
 * @buf: Array of characters to store the address and formatting.
 * @index: The index at which the number starts in the buffer.
 * @len: Length of the address.
 * @w: Width specifier.
 * @flgs: Flags specifying formatting.
 * @padding: Character used for padding.
 * @extrac: Extra character, if any.
 * @padstart: Index at which padding should start.
 *
 * Return: Writes a memory address to a character buffer with formatting
 */
int write_pointer_to_buffer(char buf[], int index, int len,
			    int w, int flgs, char padding,
			    char extrac, int padstart)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			buf[i] = padding;
		buf[i] = '\0';
		if (flgs & F_MINUS && padding == ' ')
		{
			buf[--index] = 'x';
			buf[--index] = '0';
			if (extrac)
				buf[--index] = extrac;
			return (write(1, &buf[index], len)
				+ write(1, &buf[3], i - 3));
		}
		else if (!(flgs & F_MINUS) && padding == ' ')
		{
			buf[--index] = 'x';
			buf[--index] = '0';
			if (extrac)
				buf[--index] = extrac;
			return (write(1, &buf[3], i - 3)
				+ write(1, &buf[index], len));
		}
		else if (!(flgs & F_MINUS) && padding == '0')
		{
			if (extrac)
				buf[--padstart] = extrac;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[padstart], i - padstart) +
				write(1, &buf[index],
				      len - (1 - padstart) - 2));
		}
	}
	buf[--index] = 'x';
	buf[--index] = '0';
	if (extrac)
		buf[--index] = extrac;
	return (write(1, &buf[index], BUFF_SIZE - index - 1));
}
