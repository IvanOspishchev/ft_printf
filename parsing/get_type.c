/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:44:04 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/25 13:47:20 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
