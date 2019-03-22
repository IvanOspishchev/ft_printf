/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:42:44 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 22:49:58 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_parsing.h"

int get_precision(char **str)
{
	char	*str_precision;
	int		num_precision;

	str_precision = NULL;
	if (**str != '.')
		return (0);
	(*str)++;
	while (**str && ft_isdigit(**str))
	{
		ft_strpush(&str_precision, **str);
		(*str)++;
	}
	num_precision = overflow_handle(str_precision);
	ft_strdel(&str_precision);
	return (num_precision);
}
