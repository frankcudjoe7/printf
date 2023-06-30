#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);

int print_int(int num, int width, int flag_zero, int precision);
int print_unsigned(unsigned int num, int width, int flag_zero, int precision);
int print_string(char *string, int width, int precision);
int print_octal(unsigned int num, int width, int flag_zero, int precision);
int print_binary(unsigned int num, int width, int flag_zero, int precision);

int print_hex(unsigned int num, int width, int flag_zero, int precision, int uppercase);
int print_special_string(char *string, int width, int precision);
int print_pointer(void *ptr, int width, int flag_zero, int precision);
int print_reversed_string(char *str, int width, int precision);

#endif
