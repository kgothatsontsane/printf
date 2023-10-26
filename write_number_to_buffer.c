#include "main.h"

/**
 * write_number_to_buffer - Prints a numeric value with specified formatting
 * @negative: Flag indicating if the value is negative.
 * @ind: Index at which the numeric value starts in the buffer.
 * @buf: Array of characters to store the numeric value and formatting.
 * @flgs: Flags specifying formatting.
 * @w: Width specifier.
 * @prec: prec specifier
 * @sz: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number_to_buffer(int negative, int index, char buf[],
			   int flags, int w, int prec, int sz)
{
	int length = BUFF_SIZE - index - 1;
	char padding = ' ', extra_ch = 0;

	UNUSED(sz);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num_to_buffer(index, buf, flags, w, prec,
				    length, padding, extra_ch));
}