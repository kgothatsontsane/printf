#include "main.h"

/**
 * print_rot13string - Outputs a string in rot13.
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size.
 * Return: The count of characters transformed
 */
int print_rot13string(va_list arguments, char output_buffer[],
		      int format_flags, int output_width,
		      int precision_spec, int size_spec)
{
	char rot_char;
	char *string;
	unsigned int index_str, index_rot;
	int char_count = 0;
	char alphabt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(arguments, char *);
	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(output_width);
	UNUSED(precision_spec);
	UNUSED(size_spec);

	if (string == NULL)
		string = "(AHYY)";
	for (index_str = 0; string[index_str]; index_str++)
	{
		for (index_rot = 0; alphabt[index_rot]; index_rot++)
		{
			if (alphabt[index_rot] == string[index_str])
			{
				rot_char = rot13[index_rot];
				write(1, &rot_char, 1);
				char_count++;
				break;
			}
		}
		if (!alphabt[index_rot])
		{
			rot_char = string[index_str];
			write(1, &rot_char, 1);
			char_count++;
		}
	}
	return (char_count);
}
