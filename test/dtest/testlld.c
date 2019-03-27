/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:08:40 by nparker           #+#    #+#             */
/*   Updated: 2019/03/25 15:38:09 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int main()
{
    printf("orig:  %hd\n", 4);
    ft_printf("my func 1:  %hd\n\n", 4);
    printf("orig:  %hd\n", 0);
    ft_printf("my func 2:  %hd\n\n", 0);
    printf("orig:  %hd\n", -1);
    ft_printf("my func 3:  %hd\n\n", -1);
    printf("orig:  %hd\n", 10);
    ft_printf("my func 4:  %hd\n\n", 10);
    printf("orig:  %hd\n", 256);
    ft_printf("my func 5:  %hd\n\n", 256);
    printf("orig:  %hd\n", 999);
    ft_printf("my func 6:  %hd\n\n", 999);
    printf("orig:  %hd\n", -999);
    ft_printf("my func 7:  %hd\n\n", -999);
    printf("orig:  %hd\n", 9999);
    ft_printf("my func 8:  %hd\n\n", 9999);
    printf("orig:  %hd\n", -9999);
    ft_printf("my func 9:  %hd\n\n", -9999);
    printf("orig:  %hd\n", 9999999999);
    ft_printf("my func 10:  %hd\n\n", 9999999999);
    printf("orig:  %hd\n", 2147483647);
    ft_printf("my func 11:  %hd\n\n", 2147483647);
    printf("orig:  %hd\n", -2147483647);
    ft_printf("my func 12:  %hd\n\n", -2147483647);
    printf("orig:  %hd\n", 9223372036854775807);
    ft_printf("my func 13:  %hd\n\n", 9223372036854775807);
    printf("orig:  %hd\n", -9223372036854775807);
    ft_printf("my func 14:  %hd\n\n", -9223372036854775807);
    printf("orig:  %hd\n", NULL);
    ft_printf("my func 15:  %hd\n\n", NULL);
    printf("orig:  %hd\n", 'c');
    ft_printf("my func 16:  %hd\n\n", 'c');
    printf("orig:  %hd\n", 4 + 4);
    ft_printf("my func 17:  %hd\n\n", 4 + 4);
    printf("orig:  %hd\n", 4 * 4);
    ft_printf("my func 18:  %hd\n\n", 4 * 4);
    printf("orig:  %hd\n", 2.3);
    ft_printf("my func 19:  %hd\n\n", 2.3);
    printf("orig:  %hd\n", 1.0);
    ft_printf("my func 20:  %hd\n\n", 1.0);
    printf("orig:  %hd\n", -2.3);
    ft_printf("my func 21:  %hd\n\n", -2.3);
    printf("orig:  %hd\n", -1.0);
    ft_printf("my func 22:  %hd\n\n", -1.0);
    printf("orig:  %hd\n", 0004);
    ft_printf("my func 23:  %hd\n\n", 0004);
    printf("orig:  %hd\n", -0004);
    ft_printf("my func 24:  %hd\n\n", -0004);
    return (0);
}