#include "main.h"

/**
 * print_hex_up_low - Outputs a hexadecimal number in lower or upper
 * @arguments: Variadic list of arguments.
 * @map: Array of values to map the number to
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @format_flag_ch: Active char flags
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: Writes a hexadecimal number in lower or upper.
 */
int print_hex_up_low(va_list arguments, char map[], char output_buffer[],
	       int format_flags, char format_flag_ch, int output_width,
	       int precision_spec, int size_spec)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arguments, unsigned long int);
	unsigned long int init = number;

	UNUSED(output_width);

	number = cast_size_unsigned(number, size_spec);

	if (number == 0)
		output_buffer[index--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		output_buffer[index--] = map[number % 16];
		number /= 16;
	}

	if (format_flags & F_HASH && init != 0)
	{
		output_buffer[index--] = format_flag_ch;
		output_buffer[index--] = '0';
	}

	index++;

	return (write_unsigned_to_buffer
		(0, index, output_buffer, format_flags, output_width,
					 precision_spec, size_spec));
}
