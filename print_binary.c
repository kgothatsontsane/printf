#include "main.h"

/**
 * print_binary - Outputs a binary number
 * @arguments: Variadic list of arguments.
 * @output_buffer: Buffer array for printing.
 * @format_flags:  Active flags.
 * @output_width: Width of the output.
 * @precision_spec: Specification for precision.
 * @size_spec: Specification for size
 * Return: The total number of binary numbers printed.
 */
int print_binary(va_list arguments, char output_buffer[], int format_flags,
		 int output_width, int precision_spec, int size_spec)
{
	unsigned int num, divisor, index, binaryDigitSum;
	unsigned int binaryDigits[32];
	int total;

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(output_width);
	UNUSED(precision_spec);
	UNUSED(size_spec);

	num = va_arg(arguments, unsigned int);
	divisor = 2147483648;
	binaryDigits[0] = num / divisor;
	for (index = 1; index < 32; index++)
	{
		divisor /= 2;
		binaryDigits[index] = (num / divisor) % 2;
	}
	for (index = 0, binaryDigitSum = 0, total = 0; index < 32; index++)
	{
		binaryDigitSum += binaryDigits[index];
		if (binaryDigitSum || index == 31)
		{
			char z = '0' + binaryDigits[index];

			write(1, &z, 1);
			total++;
		}
	}
	return (total);
}
