#include "main.h"

int print_hex(unsigned int num, int width, int flag_zero, int precision, int uppercase)
{
    // Implementation for printing a hexadecimal number
    // with the spcified width, flag_zero, and precision
    // ...
    int count = 0;
    int digits = 0;
    unsigned int temp = num;
    do
    {
        temp /= 16;
        digits++;
    } while (temp != 0);
    while (digits < width)
    {
        if (flag_zero)
        {
            _putchar('0');
        }
        else
        {
            _putchar(' ');
        }
        digits++;
        count++;
    }
    while (digits > 0)
    {
        unsigned int digit = num % 16;
        if (digit < 10)
        {
            _putchar('0' + digit);
        }
        else
        {
            if (uppercase)
            {
                _putchar('A' + (digit - 10));
            }
            else
            {
                _putchar('a' + (digit - 10));
            }
        }
        num /= 16;
        digits--;
        count++;
    }
    return count;
}

int_print_special_string(char *string, int width, int precision)
{
    // Implementation for printing a string with special characters
    // according to the specified width and precision
    //...
    int count = 0;
    if (string != NULL)
    {
        while (*string != '\0')
        {
            if (*string < 32 || *string >= 127)
            {
                _putchar('\\');
                _putchar('x');
                count += 2;
                int digits = 0;
                unsigned int temp = *string;
                do
                {
                    temp /= 16;
                    digits++;
                } while (temp != 0);
                while (digits > 0)
                {
                    unsigned int digit = *string % 16;
                    if (digit < 10)
                    {
                        _putchar('0' + digit);
                    }
                    else
                    {
                        _putchar('A' + (digit - 10));
                    }
                    *string /= 16;
                    digits--;
                    count++;
                }
            }
            else
            {
                _putchar(*string);
                count++;
            }
            string++;
        }
    }
    return count;
}

int print_pointer(void *ptr, int width, int flag_zero, int precision)
{
    // Implementation for printing a pointer
    // with the specified width, flag_zero, and precision
    //...
    int count = 0;
    if (ptr == NULL)
    {
        _putchar('(');
        _putchar('n');
        _putchar('i');
        _putchar('l');
        _putchar(')');
        count += 5;
    }
    else
    {
        _putchar('0');
        _putchar('x');
        count += 2;
        count += print_hex((unsigned int)ptr, 0);
    }
    return count;
}

int print_reversed_string(char *str, int width, int precision)
{
    // Implementation for printing a reversed string
    // with the specified width and precision
    //...
    int count = 0;
    if (str != NULL)
    {
        int length = 0;
        while (*str != '\0')
        {
            length++;
            str++;
        }
        str--;
        while (length > 0)
        {
            _putchar(*str);
            str--;
            length--;
            count++;
        }
    }
    return count;
}
