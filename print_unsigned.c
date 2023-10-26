#include "main.h"

/**
 * print_unsigned - Outputs an unsigned number
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: Writes an unsigned number.
 */
int print_unsigned(va_list arguments, char output_buffer[],
		   int format_flags, int output_width, int precision_spec,
		   int size_spec)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arguments, unsigned long int);

	number = cast_size_unsigned(number, size_spec);

	if (number == 0)
		output_buffer[index--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		output_buffer[index--] = (number % 10) + '0';
		number /= 10;
	}

	index++;

	return (write_unsigned_to_buffer
		(0, index, output_buffer, format_flags, output_width,
					 precision_spec, size_spec));
}
