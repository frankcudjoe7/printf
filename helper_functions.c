#include "main.h"

int print_int(int num, int width, int flag_zero, int precision)
{
    // Implementation for printing an integer
    // with the specified width, flag_zero, and precision
    // ...
    int count = 0;
    int digits = 0;
    int temp = num;
    if (num < 0)
    {
        _putchar('-');
        count++;
        num *= -1;
        temp *= -1;
    }
    do
    {
        temp /= 10;
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
        int digit = num % 10;
        _putchar('0' + digit);
        num /= 10;
        digits--;
        count++;
    }
    return count;
}

int print_unsigned(unsigned int num, int width, int flag_zero, int precision)
{
    // Implementation for printing an unsigned integer
    // with the specified width, flag_zero, and precision
    // ...
    int count = 0;
    int digits = 0;
    unsigned int temp = num;
    do
    {
        temp /= 10;
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
        unsigned int digit = num % 10;
        _putchar('0' + digit);
        num /= 10;
        digits--;
        count++;
    }
    return count;
}

int print_string(char *string, int width, int precision)
{
    // Implementation for printing a string
    // with the specified width and precision
    // ...
    int count = 0;
    if (string != NULL)
    {
        while (*string != '\0')
        {
            _putchar(*string);
            string++;
            count++;
        }
    }
    return count;
}

int print_octal(unsigned int num, int width, int flag_zero, int precision)
{
    // Implementation for printing an octal number
    // with the specified width, flag_zero, and precision
    // ...
    int count = 0;
    int digits = 0;
    unsigned int temp = num;
    do
    {
        temp /= 8;
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
        unsigned int digit = num % 8;
        _putchar('0' + digit);
        num /= 8;
        digits--;
        count++;
    }
    return count;
}

int print_binary(unsigned int num, int width, int flag_zero, int precision)
{
    // Implementation for printing a binary number
    // with the specified width, flag_zero, and precision
    // ...
    int count = 0;
    int digits = 0;
    unsigned int temp = num;
    do
    {
        temp /= 2;
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
        unsigned int digit = num % 2;
        _putchar('0' + digit);
        num /= 2;
        digits--;
        count++;
    }
    return count;
}

