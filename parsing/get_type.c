/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:44:04 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 22:51:56 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_parsing.h"

char get_type(char **str)
{
	char type;

	type = 0;
	while (**str != '\0') {
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
