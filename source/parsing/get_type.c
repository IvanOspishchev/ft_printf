/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:44:04 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/04 18:10:52 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char get_type(char **str)
{
	char type;
	char *temp;

	type = 0;
	while (**str != '\0') 
	{
		if ((ft_isalpha(**str) || **str == '%')  && **str != 'l' && **str != 'h' && **str != 'L')
		{
			temp = *str;
			type = **str;
			*str = ft_strdup(temp + 1);
			ft_strdel(&temp);
			break;
		}
		temp = *str;
		*str = ft_strdup(temp + 1);
		ft_strdel(&temp);
	}
	return (type);
}
