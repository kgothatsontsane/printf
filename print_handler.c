#include "main.h"
/**
 * print_handler - Processes and prints data according to the format specifier.
 * @format: The formatted string specifying how to print the arguments.
 * @a_list: The a_list of arguments to be printed.
 * @index: A reference to the current position within the format string.
 * @buf: The buffer used for printing.
 * @flgs: Active formatting flags.
 * @wd: Width specification.
 * @prec: Precision specification.
 * @sz: Size specification
 *
 * Return: The number of characters printed or special return values (-1, 1, 2)
 */
int print_handler(const char *format, int *index, va_list a_list, char buf[],
		  int flgs, int wd, int prec, int sz)
{
	int ind, unknown_length = 0, charCount = -1;

	fmt_t formatSpecifiers[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hexadecimal}, {'X', print_hex_upper},
		{'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}};
	for (ind = 0; formatSpecifiers[ind].format != '\0'; ind++)
		if (format[*index] == formatSpecifiers[ind].format)
			return (formatSpecifiers[ind].fn(a_list, buf, flgs, wd,
							 prec, sz));

	if (formatSpecifiers[ind].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (wd)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_length += write(1, &format[*index], 1);
		return (unknown_length);
	}
	return (charCount);
}
