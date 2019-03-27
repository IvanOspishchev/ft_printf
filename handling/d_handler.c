/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:15:10 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/25 16:07:25 by vice-wra         ###   ########.fr       */
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
        *arg = (short)*arg;
}

void del_minus(char **str)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(*str) - 1;
	while (++i < len)
		(*str)[i] = (*str)[i + 1];
	(*str)[i] = 0;
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
    int        j;
    char    *temp;
    int        len;

    i = 0;
    j = 0;
    len = ft_strlen(*substr);
    temp = ft_strnew(form_string->precision + 1);
    while (i < form_string->precision - len)
    {
        temp[i] = '0';
        i++;
    }
    while (len--)
    {
        temp[i] = (*substr)[j];
        i++;
        j++;
    }
    free(*substr);
    *substr = ft_strdup(temp);
    free(temp);
}

void width_insert_left(char **new_str, char *substr, int width, char c)
{
	int i;

    i = 0;
    while (width-- > 0)
        (*new_str)[i++] = c;
    while (*substr)
        (*new_str)[i++] = *substr++;
	(*new_str)[i] = '\0';
}

void width_insert_right(char **new_str, char *substr, int width, char c)
{
	int i;

    i = 0;
    while (*substr)
        (*new_str)[i++] = *substr++;
    while (width-- > 0)
        (*new_str)[i++] = c;
	(*new_str)[i] = '\0';
}

void width_insert(t_fs *form_string, char **substr)
{
	int width;
	char c;
	char *new_str;

	c = ' ';
	width = ft_max(form_string->width - ft_strlen(*substr), 0);
	if (ft_strchr(form_string->flags, '+'))
		width--;
	new_str = ft_strnew(ft_strlen(*substr) + width);
	if (ft_strchr(form_string->flags, '0'))
		c = '0';
	if (ft_strchr(form_string->flags, '-'))
		width_insert_right(&new_str, *substr, width, c);
	else
		width_insert_left(&new_str, *substr, width, c);
	free(*substr);
	*substr = new_str;
}

char get_sign(t_fs *form_string, long long arg)
{
	char sign;

	if (arg > 0 && ft_strchr(form_string->flags, '+'))
		sign = '+';
	else if (arg > 0)
		sign = 0;
	else if (arg < 0)
		sign = '-';
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
	*str = new_str;
}

void ft_replace(char **str, char *substr)
{
    char *temp;
    char *new_str;
    char *tempfree;
    int i;
    int len;

    i = 0;
    temp = ft_strchr(*str, '%');
    len = temp - *str;
    while (*temp && ((!ft_isalpha(*temp) || *temp == 'h' || *temp == 'l' || *temp == 'L')))
        temp++;
    temp++;
    new_str = ft_strnew(len + ft_strlen(substr) + ft_strlen(*str) - (temp - *str));
    while (len--)
    {
        new_str[i] = (*str)[i];
        i++;
    }
    while (*substr)
        new_str[i++] = *substr++;
    while (*temp)
        new_str[i++] = *temp++;
    tempfree = *str;
    *str = new_str;
    // free(tempfree);
}

void d_handler(t_fs *form_string, long long arg, char **format)
{
	char *substr;
	char sign;

	substr = NULL;
	cast(form_string, &arg);
	sign = get_sign(form_string, arg);
	num_insert(&substr, arg, form_string);
	precision_insert(form_string, &substr);
	if (sign == '-')
		add_sign(&substr, '-');
	else if (sign == '+')
		add_sign(&substr, '+');
	width_insert(form_string, &substr);		
	ft_replace(format, substr);
}

// int main(void)
// {
// 	t_fs fs;
// 	long int a;

// 	char *str;

// 	fs.flags = ft_strdup("+0");
// 	fs.width = 4;
// 	fs.precision = 0;
// 	fs.size = ft_strdup("ll");
// 	fs.type = 'd';
// 	str = ft_strdup("hello%+010d");
// 	d_handler(&fs, 500, &str);
// 	printf("%s\n", str);
// 	printf("hello%04lld\n", 500);
// }