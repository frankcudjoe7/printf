#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *p = format;

    while (*p != '\0')
    {
        if (*p == '%')
        {
            // Handle format specifier
            p++;
            if (*p == '\0')
                break;

            int flag_zero = 0;
            if (*p == '0')
            {
                flag_zero = 1;
                p++;
            }

            int width = 0;
            while (*p >= '0' && *p <= '9')
            {
                width = (width * 10) + (*p - '0');
                p++;
            }

            int precision = -1;
            if (*p == '.')
            {
                precision = 0;
                p++;
                while (*p >= '0' && *p <= '9')
                {
                    precision = (precision * 10) + (*p - '0');
                    p++;
                }
            }

            if (*p == '%')
            {
                _putchar('%');
                count++;
            }
            else if (*p == 'd' || *p == 'i')
            {
                int num = va_arg(args, int);
                count += print_int(num, width, flag_zero, precision);
            }
            else if (*p == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_unsigned(num, width, flag_zero, precision);
            }
            else if (*p == 's')
            {
                char *str = va_arg(args, char *);
                count += print_string(str, width, precision);
            }
            else if (*p == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_octal(num, width, flag_zero, precision);
            }
            else if (*p == 'x')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_hex(num, 0, width, flag_zero, precision, 0);
            }
            else if (*p == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_hex(num, width, flag_zero, precision, 1);
            }
            else if (*p == 'S')
            {
                char *str = va_arg(args, char *);
                count += print_special_string(str, width, precision);
            }
            else if (*p == 'p')
            {
                void *ptr = va_arg(args, void *);
                count += print_pointer(ptr, width, flag_zero, precision);
            }
            else if (*p == 'r')
            {
                char *str = va_arg(args, char *);
                count += print_reversed_string(str, width, precision);
            }
            else
            {
                _putchar('%');
                _putchar(*p);
                count += 2;
            }
        }
        else
        {
            // Normal character
            _putchar(*p);
            count++;
        }

        p++;
    }

    va_end(args);

    return count;
}

