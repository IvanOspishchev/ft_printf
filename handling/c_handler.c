/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:01:33 by vice-wra          #+#    #+#             */
/*   Updated: 2019/03/26 19:31:14 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			c_handler(t_fs *form_string, int arg, char **format)
{
    char *substr;
    char sign;

    substr = ft_strnew(1);
	sign = get_sign(form_string, arg);
    *substr = (char)arg;
    width_insert(form_string, &substr);
	ft_replace(format, substr);
}