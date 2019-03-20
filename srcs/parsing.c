/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:38:28 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/20 16:00:40 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void arr_zero(int *arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		arr[i] = 0;
}

static char *get_flags(char **str)
{
	int states[5];
	char *flags;

	flags = NULL;
	arr_zero(states, 5);
	while (**str && (**str == '+' || **str == '-' || **str == '0' || **str == '#' || **str == ' '))
	{
		if (**str == '+' && states[0]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == '-' && states[1]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == '#' && states[2]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == ' ' && states[3]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == '0' && states[4]++ == 0)
			ft_strpush(&flags, **str);
		(*str)++;
	}
	return (flags);
}

long long overflow_handle(char *str)
{
	
}

static int get_width(char **str)
{

	long long num_width;
	char *str_width;

	str_width = NULL;
	while (**str && ft_isdigit(**str))
	{
		ft_strpush(&str_width, **str);
		num_width = ft_atoi(str_width);
		if (num_width < 0)
		{
			num_width = 0;
			while (**str && ft_isdigit(**str))
				(*str)++;
			break;
		}
		(*str)++;
	}
	return (num_width);
}

static int get_precision(char **str)
{
	return 4;
}

static char *get_size(char **str)
{
	char *spec;

	spec = NULL;
	while (**str && (**str == 'l' || **str == 'h' || **str == 'L'))
	{
		ft_strpush(&spec, **str);
		(*str)++;
	}
	return (spec);
}

static char get_type(char **str)
{
	char type;

	while (**str) {
		if ((ft_isalpha(**str) || **str == '%')  && **str != 'l' && **str != 'h' && **str != 'L')
		{
			type = **str;
			(*str)++;
			break;
		}
		(*str)++;
	}
	return (type);
}

void fs_parse(char *format, t_fs_vector *form_strings)
{
	char		*str;
	char		*percent;
	t_fs		form_string;

	str = format;
	while ((percent = ft_strchr(str, '%')))
	{
		str = ++percent;
		form_string.flags = get_flags(&str);
		form_string.width = get_width(&str);
		form_string.precision = get_precision(&str);
		form_string.size = get_size(&str);
		form_string.type = get_type(&str);
		if (form_string.type != 0)
			fs_vector_push_back(form_strings, form_string);
	}
}

void fs_vector_print(t_fs_vector *v);

int main(void)
{
	char *str = strdup("++++++++++        +++++------#####000000");
	char *flags;

	flags = get_flags(&str);
	printf("%s", flags);
	/*
	char *str1 = ft_strdup("123123123");
	char *str4 = ft_strdup("2147483647");
	char *str2 = ft_strdup("9999999999");
	char *str3 = ft_strdup("32");

	printf("%d\n", get_width(&str1));
	printf("%d\n", get_width(&str2));
	printf("%d\n", get_width(&str3));
	printf("%d\n", get_width(&str4));
	*/

	/*t_fs_vector v;

	v = fs_vector_create(4);
	char str[50] = "hello, %+0d %0hd, %0lld hello %%2423g";
	fs_parse(str, &v);
	fs_vector_print(&v); */
}
