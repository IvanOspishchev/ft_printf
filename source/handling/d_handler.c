/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:15:10 by jblue-da          #+#    #+#             */
/*   Updated: 2019/04/19 16:54:16 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void cast(t_fs *form_string, long long *arg)
{
	if (form_string->size == NULL)
        *arg = (int)*arg;
	else if (ft_strcmp(form_string->size, "l") == 0)
        *arg = (long)*arg;
    else if (ft_strcmp(form_string->size, "hh") == 0)
        *arg = (char)*arg;
    else if (ft_strcmp(form_string->size,"h") == 0)
        *arg = (short int)*arg;
}

char del_minus(char **str)
{
	int i;
	int len;
	char sign;

	sign = **str;
	i = -1;
	len = ft_strlen(*str) - 1;
	while (++i < len)
		(*str)[i] = (*str)[i + 1];
	(*str)[i] = 0;
	return (sign);
}

void add_sign(char **str, char sign)
{
	char *new_str;
	int len;
	int i;

	i = 0;
	len = ft_strlen(*str) + 1;
	new_str = ft_strnew(len);
	new_str[0] = sign;
	while (++i < len)
		new_str[i] = (*str)[i - 1];
	ft_strdel(str);
	*str = new_str;
}

void num_insert(char **substr, long long arg, t_fs *form_string)
{
	char *number;

	number = ft_ltoa(arg);
	if (arg < 0)
		del_minus(&number);
	*substr = number;
}

void precision_insert(t_fs *form_string, char **substr)
{
	int        i;
	char 	*tempfree;
    char    *temp;
    int       len;

    i = 0;
    len = ft_strlen(*substr);
    temp = ft_strnew(form_string->precision + 1);
    while (i < form_string->precision - len)
    {
        temp[i] = '0';
        i++;
    }
	tempfree = temp;
	temp = ft_strjoin(tempfree, *substr);
    ft_strdel(substr);
	ft_strdel(&tempfree);
    *substr = temp;
}

void width_insert_left(char **new_str, char *substr, int width, char c)
{
	int i;
	char sign;

    i = 0;
	sign = -1;
	if (c == '0' && !ft_isalnum(*substr) && *substr != '%')
		sign = del_minus(&substr);
    while (width-- > 0)
        (*new_str)[i++] = c;
    while (*substr)
        (*new_str)[i++] = *substr++;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void width_insert_right(char **new_str, char *substr, int width, char c)
{
	int i;
	char sign;

    i = 0;
	if (c == '0' && !ft_isalnum(*substr) && *substr != '%')
		sign = del_minus(&substr);
    while (*substr)
        (*new_str)[i++] = *substr++;
    while (width-- > 0)
        (*new_str)[i++] = c;
	if (c == '0' && sign != -1)
	{
		add_sign(new_str, sign);
		i++;
	}
	(*new_str)[i] = '\0';
}

void width_insert(t_fs *form_string, char **substr)
{
	int width;
	char c;
	char *new_str;

	c = ' ';
	width = ft_max(form_string->width - ft_strlen(*substr), 0);
	// if (ft_strchr(form_string->flags, '+'))
	// 	width--;
	new_str = ft_strnew(ft_strlen(*substr) + width);
	if (ft_strchr(form_string->flags, '0'))
		c = '0';
	if (ft_strchr(form_string->flags, '-'))
		width_insert_right(&new_str, *substr, width, c);
	else
		width_insert_left(&new_str, *substr, width, c);
	ft_strdel(substr);
	*substr = new_str;
}

char get_sign(t_fs *form_string, long long arg)
{
	char sign;

	if (arg >= 0 && ft_strchr(form_string->flags, '+'))
		sign = '+';
	else if (arg > 0)
		sign = 0;
	else if (arg < 0)
		sign = '-';
	return (sign);		
}

void d_handler(t_fs *form_string, long long arg, char **format)
{
	char *substr;
	char sign;

	substr = NULL;
	cast(form_string, &arg);
	sign = get_sign(form_string, arg);
	num_insert(&substr, arg, form_string);
	if (form_string->precision > 0)
		precision_insert(form_string, &substr);
	if (sign == '-')
		add_sign(&substr, '-');
	else if (sign == '+')
		add_sign(&substr, '+');
	if(ft_strchr(form_string->flags, ' ') && form_string->width == ft_count_digits(arg))
		form_string->width += 1;
	else if (ft_strchr(form_string->flags, ' ') && form_string->width == 0)
		form_string->width += ft_count_digits(arg) + 1;
	width_insert(form_string, &substr);
	if (form_string->precision == 0 && arg == 0)
		ft_bzero(substr, 1);
	*format = substr;
}
