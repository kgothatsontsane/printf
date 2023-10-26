#include "main.h"

/**
 * print_hexadecimal - Outputs an unsigned number in hexadecimal notation
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: Writes an unsigned number in hexadecimal notation.
 */
int print_hexadecimal(va_list arguments, char output_buffer[],
		      int format_flags, int output_width,
		      int precision_spec, int size_spec)
{
	return (print_hex_up_low(arguments, "0123456789abcdef", output_buffer,
			   format_flags, 'x', output_width, precision_spec,
			   size_spec));
}
