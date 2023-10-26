#include "main.h"

/**
 * print_percent - Outputs a a percentage sign
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size
 * Return: The number of percentage signs printed
 */
int print_percent(va_list arguments, char output_buffer[], int format_flags,
		  int output_width, int precision_spec, int size_spec)
{
	UNUSED(arguments);
	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(output_width);
	UNUSED(precision_spec);
	UNUSED(size_spec);
	return (write(1, "%%", 1));
}
