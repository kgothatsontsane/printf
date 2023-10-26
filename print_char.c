#include "main.h"

/**
 * print_char - Outputs a single character.
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size
 * Return: The number of chars printed
 */
int print_char(va_list arguments, char output_buffer[], int format_flags,
	       int output_width, int precision_spec, int size_spec)
{
	char c = va_arg(arguments, int);

	return (write_char_to_buffer(c, output_buffer, format_flags,
				     output_width, precision_spec, size_spec));
}
