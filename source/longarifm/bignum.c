/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:27:38 by nparker           #+#    #+#             */
/*   Updated: 2019/04/20 16:27:39 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bignum        big_num_create_by_str(char sign, char *int_part, char *frac_part)
{
    t_bignum num;

    num.sign = sign;
    num.int_part = str_create_str(int_part);
    num.frac_part = str_create_str(frac_part);
    return (num);
}

t_bignum        big_num_create_by_size(char sign, int i_part, int f_part)
{
    t_bignum num;

    num.sign = sign;
    num.int_part = str_create_size(i_part);
    num.frac_part = str_create_size(f_part);
    return (num);
}


void     swap_comp_str(t_string *s1, t_string *s2)
{
    t_string tmp;

    if (str_len(s1) < str_len(s2))
    {
        tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
    }
}

char            frac_sum(t_string l, t_string r, t_string *res)
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
        num_res = (rem + (str_at(&l, i) - '0' + str_at(&r, i) - '0')) % 2 + '0';
        rem = (rem + str_at(&l, i) + str_at(&r, i) - 2 * '0') / 2;
        str_pushchar(res, num_res);
        --i;
    }
    str_rev(res);
    return (rem);
}

void            int_sum(t_string l, t_string r, t_string *res, char rem)
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
        num_res = (rem + (str_at(&l, i) + str_at(&r, j) - 2 * '0')) % 2 + '0';
        rem = (rem + str_at(&l, i) + str_at(&r, j) - 2 * '0') / 2;
        str_pushchar(res, num_res);
        --i;
    }
    while (i >= 0)
    {
        num_res = (rem + (str_at(&l, i) - '0')) % 2 + '0';
        rem = (rem + str_at(&l, i) - '0') / 2;
        str_pushchar(res, num_res);
        --i;
    }
    if (rem > 0)
        str_pushchar(res, rem + '0');
    str_rev(res);
}

t_bignum        bin_sum(t_bignum *l, t_bignum *r)
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


char mult_frac(t_string s, t_string *res)
{
	char *str;
	int i;
	char res1;

	i = 0;
	res1 = str_at(&s, 0);
	str = ft_strnew(s.size);
	while (i < s.size - 1)
	{
		str[i] = str_at(&s, i + 1);
		i++;
	}
	str[i] = '0';
	str[i + 1] = 0;
	*res = str_create_str(str);
	return(res1);
}

void            mult(t_string s, t_string *res, char rem)
{
	char *str;
	int i;

	i = 0;
	str = ft_strnew(s.size + 1);
	while (i < s.size)
	{
		str[i] = str_at(&s, i);
		i++;
	}
	str[i] = rem;
	str[i + 1] = '\0';
	*res = str_create_str(str);
}

// t_bignum        bin_minus(t_bignum *l, t_bignum *r)
// {
//     t_bignum    res;
//     char        rem;

//     res.int_part = str_create_size(10);
//     res.frac_part = str_create_size(10);
//     rem = frac_minus(l->frac_part, r->frac_part, &res.frac_part);
//     int_minus(l->int_part, r->int_part, &res.int_part, rem);
//     return res;
// }


char            divide(t_string s, t_string *res)
{
	char *str;
	int i;
	char rem;

	i = 0;
	str = ft_strnew(s.size);
	while (i < s.size - 1)
	{
		str[i] = str_at(&s, i);
		i++;
	}
	if (s.size == 1)
		str[0] = '0';
	rem = str_at(&s, 0);
	str[s.size] = 0;
	*res = str_create_str(str);
	return (rem);
}

void            divide_frac(t_string s, t_string *res, char rem)
{
	char *str;
	int i;

	i = 0;
	str = ft_strnew(s.size + 1);
	str[0] = rem;
	while (i < s.size)
	{
		str[i + 1] = str_at(&s, i);
		i++;
	}
	str[i + 1] = 0;
	*res = str_create_str(str);

}

t_bignum        bin_mult(t_bignum *l)
{
 	t_bignum    res;
    char        rem;

    res = big_num_create_by_size(l->sign, 1, 1);
	rem = mult_frac(l->frac_part, &res.frac_part);
	mult(l->int_part, &res.int_part, rem);
	return (res);
}

t_bignum        bin_divide(t_bignum *l)
{
	t_bignum    res;
    char        rem;

    res = big_num_create_by_size(l->sign, 1, 1);
	rem = divide(l->int_part, &res.int_part);
	divide_frac(l->frac_part, &res.frac_part, rem);
	return (res);
}

void        big_num_destroy(t_bignum *num)
{
	str_destroy(&num->int_part);
	str_destroy(&num->frac_part);
	free(num);
	num = NULL;
}