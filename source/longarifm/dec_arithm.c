/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_arithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:50:00 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/17 13:15:50 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char            frac_dec_mult(t_string n, t_string *res)
{
    int i;
    char rem;
    char num_res;

    rem = 0;
    i = str_len(&n) - 1;
    while (i >= 0)
    {
        num_res = (rem + (str_at(&n, i) - '0') * 2) % 10 + '0';
        rem = (rem + ((str_at(&n, i) - '0') * 2)) / 10;
        str_pushchar(res, num_res);
        --i;
    }
    str_rev(res);
    return (rem);
}

void            int_dec_mult(t_string n, t_string *res, char rem)
{
    int i;
    int j;
    char num_res;

    j = 0;
    i = str_len(&n);
    while (--i >= 0)
    {
        num_res = (rem + (str_at(&n, i) - 48) * 2) % 10 + '0';
        rem = (rem + (str_at(&n, i) - 48) * 2) / 10;
        str_pushchar(res, num_res);
    }
    if (rem > 0)
        str_pushchar(res, rem + '0');
    str_rev(res);
}

t_bignum        dec_mult(t_bignum *n)
{
    t_bignum    res;
    char        rem;

    if (n->sign == '+')
        res.sign = '+';
    else if (n->sign == '-')
        res.sign = '-';
    // else
    //     return bin_minus(l, r);
    res.int_part = str_create_size(10);
    res.frac_part = str_create_size(10);
    rem = frac_dec_mult(n->frac_part, &res.frac_part);
    int_dec_mult(n->int_part, &res.int_part, rem);
    return res;
}

char            frac_dec_div(t_string n, t_string *res, char rem)
{
    int i;
    char num_res;

    i = str_len(&n) - 1;
    while (i >= 0)
    {
        num_res = (rem + (str_at(&n, i) - '0') / 2) % 10 + '0';
        rem = (rem + ((str_at(&n, i) - '0') / 2)) / 10;
        str_pushchar(res, num_res);
        --i;
    }
    str_rev(res);
    return (rem);
}

char            int_dec_div(t_string n, t_string *res)
{
    int i;
    char num_res;
    int carry;

    i = str_len(&n) - 1;
	carry = 0;
	num_res = 0;
    while (i >= 0)
    {
        num_res = (carry - 48) + ((str_at(&n, i) - 48) / 2) + '0';
		
		--i;
		str_pushchar(res, num_res);
    }
    str_rev(res);
	return (carry);
}

t_bignum        dec_div(t_bignum *n)
{
    t_bignum    res;
    char        cur;
	int 		i;

	i = 0;
    if (n->sign == '+')
        res.sign = '+';
    else if (n->sign == '-')
        res.sign = '-';
	if (n->int_part.data[0] == '1')
	{
		res = big_num_create_by_str(n->sign, "0", "5");
		return (res);
	}
	char rem = 0;
    res = big_num_create_by_size(n->sign, 1, 1);
	while (i < n->frac_part.size)
	{
		cur = rem + ((str_at(&n->frac_part,i) - 48) * 5) + ((str_at(&n->frac_part,i) - 48) % 2 * 10) + 48;
		if (cur != '0')
			str_pushchar(&res.frac_part, cur);
		i++;
	}
	return (res);
}


static char            frac_sum(t_string l, t_string r, t_string *res)
{
    int i;
    char rem;
    char num_res;

    rem = 0;
    swap_comp_str(&l, &r);
    i = str_len(&l);
    while (--i >= str_len(&r))
        str_pushchar(res, str_at(&l, i));
    while (i >= 0)
    {
        num_res = (rem + (str_at(&l, i) - '0' + str_at(&r, i) - '0')) % 10 + '0';
        rem = (rem + str_at(&l, i) + str_at(&r, i) - 2 * '0') / 10;
        str_pushchar(res, num_res);
        --i;
    }
    str_rev(res);
    return (rem);
}

static void            int_sum(t_string l, t_string r, t_string *res, char rem)
{
    int i;
    int j;
    char num_res;

    j = 0;
    swap_comp_str(&l, &r);
    i = str_len(&l) - 1;
    j = str_len(&r);
    while (--j >= 0)
    {
        num_res = (rem + (str_at(&l, i) + str_at(&r, j) - 2 * '0')) % 10 + '0';
        rem = (rem + str_at(&l, i) + str_at(&r, j) - 2 * '0') / 10;
        str_pushchar(res, num_res);
        --i;
    }
    while (i >= 0)
    {
        num_res = (rem + (str_at(&l, i) - '0')) % 10 + '0';
        rem = (rem + str_at(&l, i) - '0') / 10;
        str_pushchar(res, num_res);
        --i;
    }
    if (rem > 0)
        str_pushchar(res, rem + '0');
    str_rev(res);
}

t_bignum        dec_sum(t_bignum *l, t_bignum *r)
{
    t_bignum    res;
    char        rem;

    if (l->sign == '+' && r->sign == '+')
        res.sign = '+';
    else if (l->sign == '-' && r->sign == '-')
        res.sign = '-';
    // else
    //     return bin_minus(l, r);
    res.int_part = str_create_size(10);
    res.frac_part = str_create_size(10);
    rem = frac_sum(l->frac_part, r->frac_part, &res.frac_part);
    int_sum(l->int_part, r->int_part, &res.int_part, rem);
    return res;
}