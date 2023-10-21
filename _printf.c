#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                printed_chars += write(1, &c, 1); // Write a character to stdout
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s)
                    printed_chars += write(1, s, _strlen(s)); // Write a string to stdout
                else
                    printed_chars += write(1, "(null)", 6);
            }
            else if (*format == '%')
            {
                printed_chars += write(1, "%", 1); // Write a '%' character
            }
            else
            {
                printed_chars += write(1, "%", 1); // Handle unsupported format specifier as '%'
                if (*format)
                    printed_chars += write(1, format, 1);
            }
        }
        else
        {
            printed_chars += write(1, format, 1); // Write regular characters
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
    int len = 0;
    while (s[len])
    {
        len++;
    }
    return len;
}
