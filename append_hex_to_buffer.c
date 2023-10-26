#include "main.h"

/**
 * append_hex_to_buffer - Add the hexadecimal representation of an ASCII code
 *  to a character buffer.
 * @buff: Array (buffer) of characters to which the hexadecimal code is added.
 * @index: Starting index for the addition.
 * @ascii: The ASCII code to be converted to hexadecimal.
 *
 * Return: Always 3, indicating three characters were appended.
 */

int append_hex_to_buffer(char ascii, char buff[], int index)
{
	char map[] = "0123456789ABCDEF";


	if (ascii < 0)
		ascii *= -1;

	buff[index++] = '\\';
	buff[index++] = 'x';

	buff[index++] = map[ascii / 16];
	buff[index] = map[ascii % 16];

        return (3);
}
