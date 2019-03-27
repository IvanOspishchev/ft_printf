/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:58:06 by ivan              #+#    #+#             */
/*   Updated: 2019/03/27 20:53:56 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

void	p_handler(t_fs *form_string, long long arg, char **format)
{
	char *substr;
	unsigned int p;
	int i;

	substr = ft_strnew(2 * sizeof(p));
   	p = (unsigned int)&arg;
	i = 2 * sizeof(p) - 1;
	printf("%p\n", &arg);
    while (i >= 0)
    {
        i--;
		substr[i] = "0123456789ABCDEF"[p & 0x0F];
        p >>= 4;
    }
	printf("%p\n", &arg);
	ft_replace(format, substr);
}
