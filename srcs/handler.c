#include "../ft_printf.h"

void handler_item(va_list *args, t_fs *form_string, char **format)
{
	if (form_string->type == 'd')
		d_handler(form_stirng, va_arg(*args, long long), format);
	else if (form_string->type == 'i')
		i_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'o')
		o_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'u')
		u_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'x')
		x_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'X')
		xx_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'f')
		f_handler(form_string, va_arg(*args, long double), format);
	else if (form_string->type == 'c')
		c_handler(form_string, va_arg(*args, char), format);
	else if (form_string->type == 's')
		s_handler(form_string, va_arg(*args, char *), format);
	else if (form_string->type == 'p')
		p_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == '%')
		pr_handler(form_string, va_arg(*args, int), format);
}

void handler(va_list *args, t_fs_vector *form_strings, char **format)
{
	int i;

	i = -1;
	while (++i < fs_vector_length(form_strings))
		handler_item(args, &form_strings->data[i], format);
}
