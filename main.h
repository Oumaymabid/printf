#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct fmt - struct op
 *
 * @fmt: input
 * @fn: input
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fm_t - Struct op
 *
 *@fmt: input
 *@fm_t: input
 */
typedef struct fmt fm_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*functions to print chars and strings*/
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*functions to print numbers*/
it print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);

#endif /*MAIN_H */
