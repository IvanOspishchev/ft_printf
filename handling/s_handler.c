/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:29:05 by ivan              #+#    #+#             */
/*   Updated: 2019/03/27 15:00:56 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* Нужно обработать ширину поля и по тестить*/


/* Обрабатывает точность и выводит столько символов
скольки соответствует точность*/
char	*s_get_precision(t_fs *form_string, char **substr)
{
	int i;
	int	precision;
	char* new_substr;

	precision = form_string->precision;
	i = 0;
	if (precision != 0)
	{
		new_substr = ft_strnew(precision + 1);
		while (precision--)
		{
			new_substr[i] = (*substr)[i];
			i++;
		}
	free(*substr);
	*substr = ft_strdup(new_substr);
	free(new_substr);
	}
	return(*substr);
}

char		*s_get_width(t_fs *form_string,char **substr)
{
	int i;
	int space;
	char	*new_sub;
	int len;


	len = (ft_strlen(*substr) + 1);
	i = 0;
	space = (form_string->width - form_string->precision);
	new_sub = ft_strnew(space + len);
	if ((form_string->width > form_string->precision) && form_string->precision != 0)
	{
		while (space < len)
			new_sub[i] = ' ';
			i++;
		while (len)
			new_sub[i++] = (*substr)[len++];
		free(*substr);
		*substr = ft_strdup(new_sub);
		free(new_sub);
		return (*substr);
	}
	else if (form_string->precision == 0)
	{
		while (form_string->width > i)
		{
			new_sub[i] = ' ';
			i++;
		}
		free(*substr);
		*substr = ft_strdup(new_sub);
		free(new_sub);
		return (*substr);
	}
	return (*substr);
}


void	s_handler(t_fs *form_string, char *arg, char **format)
{
	char *substr;
	int i;

	i = 0;
	substr = ft_strnew((char)*arg);
	while (i < (char)*arg)
		substr[i++] = (char)*arg++;
	if (form_string->precision != 0)
		s_get_precision(form_string, &substr);
	if (form_string->width != 0)
		s_get_width(form_string, &substr);
	ft_replace(format, substr);
}
