/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:35:32 by nparker           #+#    #+#             */
/*   Updated: 2019/03/26 17:03:08 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../ft_printf.h"


int main()
{
    printf("orig:  %c\n", 'c');
    ft_printf("my func 1:  %c\n\n", 'c');
    printf("orig:  %c\n", 1);
    ft_printf("my func 2:  %c\n\n", 1);
    printf("orig:  %c\n", -1);
    ft_printf("my func 3:  %c\n\n", -1);
    printf("orig:  %c\n", 10);
    ft_printf("my func 4:  %c\n\n", 10);
    printf("orig:  %c\n", 256);
    ft_printf("my func 5:  %c\n\n", 256);
    printf("orig:  %c\n", 127);
    ft_printf("my func 6:  %c\n\n", 127);
    printf("orig:  %c\n", -999);
    ft_printf("my func 7:  %c\n\n", -999);
    printf("orig:  %c\n", 9999);
    ft_printf("my func 8:  %c\n\n", 9999);
    printf("orig:  %c\n", -9999);
    ft_printf("my func 9:  %c\n\n", -9999);
    printf("orig:  %c\n", 9999999999);
    ft_printf("my func 10:  %c\n\n", 9999999999);
    printf("orig:  %c\n", 2147483647);
    ft_printf("my func 11:  %c\n\n", 2147483647);
    printf("orig:  %c\n", -2147483647);
    ft_printf("my func 12:  %c\n\n", -2147483647);
    printf("orig:  %c\n", 9223372036854775807);
    ft_printf("my func 13:  %c\n\n", 9223372036854775807);
    printf("orig:  %c\n", -9223372036854775807);
    ft_printf("my func 14:  %c\n\n", -9223372036854775807);
    printf("orig:  %c\n", NULL);
    ft_printf("my func 15:  %c\n\n", NULL);
    printf("orig:  %c\n", "str");
    ft_printf("my func 16:  %c\n\n", "str");
    printf("orig:  %c\n", 4 + 4);
    ft_printf("my func 17:  %c\n\n", 4 + 4);
    printf("orig:  %c\n", 4 * 4);
    ft_printf("my func 18:  %c\n\n", 4 * 4);
    printf("orig:  %c\n", 2.3);
    ft_printf("my func 19:  %c\n\n", 2.3);
    printf("orig:  %c\n", 1.0);
    ft_printf("my func 20:  %c\n\n", 1.0);
    printf("orig:  %c\n", -2.3);
    ft_printf("my func 21:  %c\n\n", -2.3);
    printf("orig:  %c\n", -1.0);
    ft_printf("my func 22:  %c\n\n", -1.0);
    printf("orig:  %c\n", 0004);
    ft_printf("my func 23:  %c\n\n", 0004);
    printf("orig:  %c\n", -0004);
    ft_printf("my func 24:  %c\n\n", -0004);
    printf("orig:  %c\n", "-0004");
    ft_printf("my func 25:  %c\n\n", "-0004");
    printf("orig:  %c\n", '4');
    ft_printf("my func 26:  %c\n\n", '4');


    /* test %c %c */

  printf("orig:  %c,%c\n", 'c','v');
    ft_printf("my func 1:  %c,%c\n\n", 'c','v');
    printf("orig:  %c,%c\n", 1,'c');
    ft_printf("my func 2:  %c,%c\n\n", 1,'c');
    printf("orig:  %c,%c\n", -1,'c');
    ft_printf("my func 3:  %c,%c\n\n", -1,'c');
    printf("orig:  %c,%c\n", 10);
    ft_printf("my func 4:  %c,%c\n\n", 10);
    printf("orig:  %c,%c\n", 256);
    ft_printf("my func 5:  %c,%c\n\n", 256);
    printf("orig:  %c,%c\n", 127);
    ft_printf("my func 6:  %c,%c\n\n", 127);
    printf("orig:  %c,%c\n", -999);
    ft_printf("my func 7:  %c,%c\n\n", -999);
    printf("orig:  %c,%c\n", 9999);
    ft_printf("my func 8:  %c,%c\n\n", 9999);
    printf("orig:  %c,%c\n", -9999);
    ft_printf("my func 9:  %c,%c\n\n", -9999);
    printf("orig:  %c,%c\n", 9999999999);
    ft_printf("my func 10:  %c,%c\n\n", 9999999999);
    printf("orig:  %c,%c\n", 2147483647);
    ft_printf("my func 11:  %c,%c\n\n", 2147483647);
    printf("orig:  %c,%c\n", -2147483647);
    ft_printf("my func 12:  %c,%c\n\n", -2147483647);
    printf("orig:  %c,%c\n", 9223372036854775807);
    ft_printf("my func 13:  %c,%c\n\n", 9223372036854775807);
    printf("orig:  %c,%c\n", -9223372036854775807);
    ft_printf("my func 14:  %c,%c\n\n", -9223372036854775807);
    printf("orig:  %c,%c\n", NULL);
    ft_printf("my func 15:  %c,%c\n\n", NULL);
    printf("orig:  %c,%c\n", "str");
    ft_printf("my func 16:  %c,%c\n\n", "str");
    printf("orig:  %c,%c\n", 4 + 4);
    ft_printf("my func 17:  %c,%c\n\n", 4 + 4);
    printf("orig:  %c,%c\n", 4 * 4);
    ft_printf("my func 18:  %c,%c\n\n", 4 * 4);
    printf("orig:  %c,%c\n", 2.3);
    ft_printf("my func 19:  %c,%c\n\n", 2.3);
    printf("orig:  %c,%c\n", 1.0);
    ft_printf("my func 20:  %c,%c\n\n", 1.0);
    printf("orig:  %c,%c\n", -2.3);
    ft_printf("my func 21:  %c,%c\n\n", -2.3);
    printf("orig:  %c,%c\n", -1.0);
    ft_printf("my func 22:  %c,%c\n\n", -1.0);
    printf("orig:  %c,%c\n", 0004);
    ft_printf("my func 23:  %c,%c\n\n", 0004);
    printf("orig:  %c,%c\n", -0004);
    ft_printf("my func 24:  %c,%c\n\n", -0004);
    printf("orig:  %c,%c\n", "-0004");
    ft_printf("my func 25:  %c,%c\n\n", "-0004");
    printf("orig:  %c,%c\n", '4');
    ft_printf("my func 26:  %c,%c\n\n", '4');
    return (0);
}