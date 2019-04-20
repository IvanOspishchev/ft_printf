/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:33:32 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/20 16:38:14 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void        o_handler(t_fs *form_string, unsigned long long arg, char **format)
{
    char* substr;

    substr = NULL;
    u_cast(form_string, &arg);
    if (arg > 0)
		substr = dec_to_octal(arg);
	else
		substr = ft_strdup("0");
    precision_insert(form_string, &substr);
	if (ft_strchr(form_string->flags, '#') && form_string->precision <= ft_count_digits(arg) && arg != 0)
		substr = ft_strjoin("0", substr);
	if (ft_strchr(form_string->flags, ' ') && ft_strchr(form_string->flags, '-'))
	{
		ft_strdel(&form_string->flags);
		form_string->flags = ft_strdup("-");
	}
    width_insert(form_string, &substr);
  	*format = substr;
}