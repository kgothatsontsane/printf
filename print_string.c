#include "main.h"

/**
 * print_string - Outputs a string
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size
 * Return: The number of chars in string printed
 */
int print_string(va_list arguments, char output_buffer[], int format_flags,
		 int output_width, int precision_spec, int size_spec)
{
	int len = 0, index;
	char *string = va_arg(arguments, char *);

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(output_width);
	UNUSED(precision_spec);
	UNUSED(size_spec);
	if (string == NULL)
	{
		string = "(null)";
		if (precision_spec >= 6)
			string = "      ";
	}

	while (string[len] != '\0')
		len++;

	if (precision_spec >= 0 && precision_spec < len)
		len = precision_spec;

	if (output_width > len)
	{
		if (format_flags & F_MINUS)
		{
			write(1, &string[0], len);
			for (index = output_width - len; index > 0; index--)
				write(1, " ", 1);
			return (output_width);
		}
		else
		{
			for (index = output_width - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (output_width);
		}
	}

	return (write(1, string, len));
}
