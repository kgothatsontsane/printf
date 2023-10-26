#include "main.h"

/**
 * print_reverse - Outputs a string in reverse.
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: The count of characters processed
 */

int print_reverse(va_list arguments, char output_buffer[], int format_flags,
		  int output_width, int precision_spec, int size_spec)
{
	char *string;
	int index, char_count = 0;

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(output_width);
	UNUSED(size_spec);

	string = va_arg(arguments, char *);

	if (string == NULL)
	{
		UNUSED(precision_spec);

		string = "(Null)";
	}
	for (index = 0; string[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char z = string[index];

		write(1, &z, 1);
		char_count++;
	}
	return (char_count);
}
