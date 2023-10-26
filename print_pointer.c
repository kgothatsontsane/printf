#include "main.h"

/**
 * print_pointer - Outputs the value of a pointer
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: Writes the value of a pointer
 */
int print_pointer(va_list arguments, char output_buffer[], int format_flags,
		  int output_width, int precision_spec, int size_spec)
{
	char extrac = 0, padding = ' ';
	int ind = BUFF_SIZE - 2, len = 2, pad_start = 1;
	unsigned long num_address;
	char map[] = "0123456789abcdef";
	void *address = va_arg(arguments, void *);

	UNUSED(output_width);
	UNUSED(size_spec);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	output_buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision_spec);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		output_buffer[ind--] = map[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((format_flags & F_ZERO) && !(format_flags & F_MINUS))
		padding = '0';
	if (format_flags & F_PLUS)
		extrac = '+', len++;
	else if (format_flags & F_SPACE)
		extrac = ' ', len++;

	ind++;

	return (write_pointer_to_buffer(output_buffer, ind, len,
					output_width, format_flags,
					padding, extrac, pad_start));
}
