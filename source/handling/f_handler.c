/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:10:34 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/20 16:05:03 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void f_cast(t_fs *form_string, long double *arg)
{
	if (ft_strchr(form_string->size, 'L') == 0)
		*arg = (double) *arg;
}

char f_get_sign(t_fs *form_string, long double arg)
{
	char sign;

	if (arg >= 0 && ft_strchr(form_string->flags, '+'))
		sign = '+';
	else if (arg > 0)
		sign = 0;
	else if (arg < 0)
		sign = '-';
	return (sign);		
}

void do_int_part(t_bignum *num)
{
	int i;
	int j;
	char c;
	t_bignum sum;
	t_bignum a1;

	i = 0;
	sum = big_num_create_by_str('+', "0", "0");
	while (i < num->int_part.size)
	{
		j = 0;
		t_bignum a1;
		c = num->int_part.data[i];
		a1 = big_num_create_by_str('+', &c, "0");
		while (j++ < num->int_part.size - i - 1)
			a1 = dec_mult(&a1);
		sum = dec_sum(&sum, &a1);
		++i;
	}
	num->int_part = sum.int_part;
}

void rround(t_bignum *num, int precision)
{
	t_bignum temp;

	temp = big_num_create_by_size('+', 1, precision);
	str_pushchar(&temp.int_part, '0');
	while (precision-- > 1)
		str_pushchar(&temp.frac_part, '0');
	str_pushchar(&temp.frac_part, '1');
	*num = dec_sum(num, &temp);
}

static void put_zeros(int precision, t_string *str)
{
	if (precision > str->size)
		{
			while (precision != str->size)
				str_pushchar(str, '0');
		}
}

int find_digit(t_string *s, int start)
{
	while (start < str_len(s))
	{
		if (s->data[start++] > '0')
			return (1);
	}
	return (0);
}

void do_frac_part(t_bignum *num, int precision)
{
	int i;
	int j;
	char c;
	t_bignum sum;
	t_bignum a1;

	i = 0;
	sum = big_num_create_by_str('+', "0", "0");
	while (i < num->frac_part.size)
	{
		j = 0;
		t_bignum a1;
		c = num->frac_part.data[i];
		a1 = big_num_create_by_str('+', &c, "0");
		while (j++ <= i)
			a1 = dec_div(&a1);
		sum = dec_sum(&sum, &a1);
		++i;
	}
	if (sum.frac_part.data[precision] > '4')
		if (find_digit(&sum.frac_part, precision + 1))
			rround(&sum, precision);
	if (precision > 0)
	{
		num->int_part = cust_strsub(&sum.int_part, 0, sum.int_part.size);
		num->frac_part = cust_strsub(&sum.frac_part, 0, precision);
	}
	put_zeros(precision, &num->frac_part);
}

void do_bignum_arithm(t_bignum *num, int precision)
{
	do_int_part(num);
	do_frac_part(num, precision);
}

void process_the_exponent(t_bignum *num, int exponent)
{
	int i;

	i = 0;
	if (exponent > 0)
		while (i++ < exponent)
			*num = bin_mult(num);
	else if (exponent < 0)
		while (i++ < ft_abs(exponent))
			*num = bin_divide(num);
}

t_bignum *get_the_bits(long double arg)
{
	int i;
	int byte;
	t_bignum *num;

	i = 62;
	t.d_num = (long double)arg;
	num = malloc(sizeof(t_bignum));
	num->frac_part = str_create_size(10);
	num->int_part = str_create_size(10);
	str_pushchar(&num->int_part, (t.t_double.mantissa >> 63 & 1) + 48);
	byte = 0;
	while (i >= 0)
	{
		byte = t.t_double.mantissa >> i & 1;
		str_pushchar(&num->frac_part, byte + 48);
		--i;
	}
	if (arg > 0)
		process_the_exponent(num, t.t_double.exponent - 16383);
	return (num);
}

void	f_handler(t_fs *form_string, double arg, char **format)
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
