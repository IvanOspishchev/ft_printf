/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:15:10 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/22 16:02:48 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handling.h"
char		*ft_plus_first(int nb)
{
	char*	str;
	char*	temp;

    str = (char*)malloc(sizeof(char) * ft_count_digits(nb) + 2);
	temp = ft_itoa(nb);
	str[0] = '+';
	ft_strcat(str, temp);
	return (str);
}
void	ft_cast(t_fs *form_string, long long *arg)
{
	if (ft_strcmp(form_string->size,'l'))
		*arg = (long)*arg;
	if (ft_strcmp(form_string->size,'hh'))
		*arg = (char)*arg;
	if (ft_strcmp(form_string->size,'h'))
		*arg = (short)*arg;
	if (form_string->size == NULL)
		*arg = (int)*arg;
}

void d_handler(t_fs *form_string, long long arg, char **format)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_max(form_string->precision, form_string->width) + 1));
	if (arg < 0)
	{
		*str = '-';
		i++;
	}
	if (ft_strcmp(form_string->size, "ll")
	{
		if (form_string->precision >= form_string->width)
			while (form_string->precision && i++ < form_string->precision - ft_count_digits(arg))
				str[i] = '0';
		else
		{
			if (ft_strcmp(form_string->flags, "-") == 0)
			{
				while (i++ < form_string->precision - ft_count_digits(arg))
				str[i] = '0';
				str = ft_itoa(arg);
				while (form_string->width && i++ < form_string->width - form_string->precision)
					str[i] = ' ';
			}
			else if (arg > 0 && ft_strcmp(form_string->flags, "+") == 0)
			{
				while (form_string->width && i++ < form_string->width - form_string->precision)
					str[i] = ' ';
				str[i] = '+';
				while (i++ < form_string->precision - ft_count_digits(arg))
					str[i] = '0';
				str = ft_itoa(arg);
			}
			else if (ft_strcmp(form_string->flags, "+-") || ft_strcmp(form_string->flags, "-+"))
			{
				
			}	
		}
	}
	if (ft_strcmp(form_string->size, "l")

	if (ft_strcmp(form_string->size, "hh")

	if (ft_strcmp(form_string->size, "h")

}
