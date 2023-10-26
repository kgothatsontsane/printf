#include "main.h"

/**
 * cast_size_number - casts an integer to the required size
 * @number: integer to be casted.
 * @c_size: Number indicating the type to be casted.
 *
 * Return: the casted value of number
 */
long int cast_size_number(long int number, int c_size)
{
	if (c_size == S_LONG)
		return (number);
	else if (c_size == S_SHORT)
		return ((short)number);

	return ((int)number);
}
