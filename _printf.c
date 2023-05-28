#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
  *_printf - entry point
  *@format: input.
  *Return: chars printed
  */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (p_chars);
}
/**
  *print_buffer -  prints buffer content
  *@buffer: input
  *@buff_ind: input
  */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
