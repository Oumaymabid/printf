#include "main.h"

void print_buffer(char buff[], int *buff_i);

/**
  *_printf - entry point
  *@format: input
  *Return: chars printed
  */
int _printf(const char *format, ...)
{
	int j, p = 0, p_chars = 0;
	int flags, width, precision, size, buff_d = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buff[buff_j++] = format[j];
			if (buff_i == BUFF_SIZE)
				print_buffer(buff, &buff_i);
			/* write(1, &format[j], 1);*/
			p_chars++;
		}
		else
		{
			print_buffer(buff, &buff_i);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			p = handle_print(format, &j, list, buff,
					flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}
	print_buffer(buff, &buff_i);
	va_end(list);
	return (p_chars);
}
/**
  *print_buffer -  prints buffer content
  *@buff: input
  *@buff_i: input
  */
void print_buffer(char buff[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buff[0], *buff_i);
	*buff_i = 0;
}
