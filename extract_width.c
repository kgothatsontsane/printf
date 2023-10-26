#include "main.h"

/**
 * extract_width - Determines the printing width based on the formatted_string.
 * @formatted_string: The formatted string where argument printing is defined.
 * @index: A reference to the current position within the format string.
 * @aList: The variadic list of arguments.
 *
 * Return: The calculated width for printing.
 */
int extract_width(const char *formatted_string, int *index, va_list aList)
{
        int currentPosition;
        int printingWidth = 0;

        for (currentPosition = *index + 1; formatted_string[currentPosition] !=
                     '\0'; currentPosition++)
        {
                if (digit(formatted_string[currentPosition]))
                {
                        printingWidth *= 10;
                        printingWidth += formatted_string[currentPosition] -
				'0';
                }
                else if (formatted_string[currentPosition] == '*')
                {
                        currentPosition++;
                        printingWidth = va_arg(aList, int);
                        break;
                }
                else
                        break;
        }

        *index = currentPosition - 1;

        return (printingWidth);
}
