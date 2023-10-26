#include "main.h"

/**
 * print_int - Outputs an integer
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size
 * Return: The number of integers printed
 */
int print_int(va_list arguments, char output_buffer[], int format_flags,
			  int output_width, int precision_spec, int size_spec)
{
	int index = BUFF_SIZE - 2;
	int negative = 0;
	long int value = va_arg(arguments, long int);
	unsigned long int total;

	value = cast_size_number(value, size_spec);

	if (value == 0)
		output_buffer[index--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	total = (unsigned long int)value;
	if (value < 0)
	{
		total = (unsigned long int)((-1) * value);
		negative = 1;
	}

	while (total > 0)
	{
		output_buffer[index--] = (total % 10) + '0';
		total /= 10;
	}

	index++;

	return (write_number_to_buffer
		(negative, index, output_buffer,format_flags,
		 output_width, precision_spec, size_spec));
}
