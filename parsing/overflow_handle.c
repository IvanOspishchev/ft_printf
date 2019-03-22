/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:41:37 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:42:10 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_parsing.h"

int overflow_handle(char *str)
{
	int i;
	long long num;

	if (str == NULL)
		return (0);
	i = 0;
	num = 0;
	while (str[i] && num <= 2147483647)
	{
		num *= 10;
		num += str[i] - 48;
		++i;
	}
	if (num > 2147483647)
		num = 0;
	return (num);
}
