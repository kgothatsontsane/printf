#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The formatted string containing the text and format specifiers.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, total = 0, count = 0, buffer_index = 0;
	int flags, width, precision, size;
	va_list a_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(a_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				print_to_buffer(buffer, &buffer_index);

			count++;
		}
		else
		{
			print_to_buffer(buffer, &buffer_index);
			flags = retrieve_flags(format, &i);
			width = extract_width(format, &i, a_list);
			precision = determine_precision(format, &i, a_list);
			size = detect_size(format, &i);
			++i;
			total = print_handler(format, &i, a_list, buffer,
					      flags, width, precision, size);
			if (total == -1)
				return (-1);
			count += total;
		}
	}
	print_to_buffer(buffer, &buffer_index);
	va_end(a_list);
	return (count);
}
