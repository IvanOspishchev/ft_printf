/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:39:27 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/04 17:54:44 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int get_width(char **str)
{

	int num_width;
	char *str_width;
	char *temp;

	str_width = NULL;
	while (**str && ft_isdigit(**str))
	{
		temp = *str;
		ft_strpush(&str_width, **str);
		*str = ft_strdup(temp + 1);
		ft_strdel(&temp);
	}
	num_width = overflow_handle(str_width);
	ft_strdel(&str_width);
	return (num_width);
}