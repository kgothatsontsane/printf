#include "main.h"

/**
 * cast_size_unsigned - casts an unsigned int to the required size
 * @number: unsigned integer to be casted
 * @c_size: the size the number should  be casted to
 *
 * Return: the casted value of number
 */
unsigned long int cast_size_unsigned(unsigned long int number, int c_size)
{
	if (c_size == S_LONG)
		return (number);
	else if (c_size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
