#include "main.h"

/**
 * print_non_printable - Outputs ASCII codes in HEX for non-printable chars
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: Writes ASCII codes in hexadecimal
 */
int print_non_printable(va_list arguments, char output_buffer[],
			int format_flags, int output_width,
			int precision_spec, int size_spec)
{
	int index = 0, offset = 0;
	char *string = va_arg(arguments, char *);

	UNUSED(format_flags);
	UNUSED(output_width);
	UNUSED(precision_spec);
	UNUSED(size_spec);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[index] != '\0')
	{
		if (printable(string[index]))
			output_buffer[index + offset] = string[index];
		else
			offset += append_hex_to_buffer
				(string[index], output_buffer, index + offset);

		index++;
	}

	output_buffer[index + offset] = '\0';

	return (write(1, output_buffer, index + offset));
}
