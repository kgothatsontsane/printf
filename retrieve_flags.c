#include "main.h"

/**
 * retrieve_flags - Collects the active formatting flags from the format string.
 * @formatted_string: The formatted string where argument printing is defined.
 * @position: A reference to the current position within the format string.
 * Return: Flags corresponding to the active formatting flags.
 */
int retrieve_flags(const char *formatted_string, int *index)
{
        /* FLAG MAPPING */
        /* - + 0 # ' ' */
        /* 1 2 4 8  16 */
        int flagIndex, currentPosition;
        int flagCount = 0;
        const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
        const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

        for (currentPosition = *index + 1; formatted_string[currentPosition]
                     !='\0'; currentPosition++)
        {
                for (flagIndex = 0; FLAG_CHARACTERS[flagIndex]
                             != '\0'; flagIndex++)
                        if (formatted_string[currentPosition] ==
                            FLAG_CHARACTERS[flagIndex])
                        {
                                flagCount |= FLAG_VALUES[flagIndex];
                                break;
                        }
                if (FLAG_CHARACTERS[flagIndex] == 0)
                        break;
        }

        *index = currentPosition - 1;

        return (flagCount);
}
