/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:39:27 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:42:04 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_parsing.h"

int get_width(char **str)
{

	int num_width;
	char *str_width;

	str_width = NULL;
	while (**str && ft_isdigit(**str))
	{
		ft_strpush(&str_width, **str);
		(*str)++;
	}
	num_width = overflow_handle(str_width);
	ft_strdel(&str_width);
	return (num_width);
}