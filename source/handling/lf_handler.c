/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:17:11 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/19 20:19:57 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			lf_handler(t_fs *form_string, long double arg, char **format)
{
	char *str;
	char sign;
	t_bignum *num;

	sign = f_get_sign(form_string, arg);
	if (arg < 0)
		arg = arg * -1.0;
	if (form_string->precision == -1)
		form_string->precision = 6;
	num = get_the_bits(arg);
	do_bignum_arithm(num, form_string->precision);
	if (form_string->precision > 0)
	{
		str = cust_strjoin_left(&num->int_part, ".");
		str = cust_strjoin_right(str, &num->frac_part);
	}
	else 
		str = cust_strdup(&num->int_part);
	if (sign == '-')
		add_sign(&str, '-');
	else if (sign == '+')
		add_sign(&str, '+');
	width_insert(form_string, &str);
	*format = str;
}
