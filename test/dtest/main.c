/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:02:16 by vice-wra          #+#    #+#             */
/*   Updated: 2019/03/25 15:53:27 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
#include <stdio.h>

int main()
{
    // %hhd   tests;
    // %d tests
	printf("d tests : \n\n");
	ft_printf("my func1:  %d\n", 4);
    printf("orig: %d\n\n", 4);
    ft_printf("my func2:  %d\n", 99999);
    printf("orig: %d\n\n", 99999);
    ft_printf("my func3:  %d\n", -99999);
    printf("orig: %d\n\n", -99999);
    ft_printf("my func4:  %d\n", -1);
    printf("orig: %d\n\n", -1);
    ft_printf("my func5:  %d\n", "dfdf");
    printf("orig: %d\n\n", "dfdf");
    ft_printf("my func6:  %d\n", 0);
    printf("orig: %d\n\n", 0);
    ft_printf("my func7:  %d\n", 9999999999);
    printf("orig: %d\n\n", 9999999999);
    ft_printf("my func8:  %d\n", 2.984);
    printf("orig: %d\n\n", 2.984);
    ft_printf("my func9:  %d\n", 3,44);
    printf("orig: %d\n\n", 3,44);
    ft_printf("my func10:  %d\n", -999999999);
    printf("orig: %d\n\n", -999999999);
    ft_printf("my func11:  %d\n", 232323);
    printf("orig: %d\n\n", 232323);
    ft_printf("my func12:  %d\n", 0.5);
    printf("orig: %d\n\n", 0.5);
    ft_printf("my func13:  %d\n", 'c');
    printf("orig: %d\n\n", 'c');
    ft_printf("my func14:  %d\n", NULL);
    printf("orig: %d\n\n", NULL);
    ft_printf("my func15:  %d\n", 2 + 3);
    printf("orig: %d\n\n", 2 + 3);
    ft_printf("my func16:  %d\n", 99 / 11);
    printf("orig: %d\n\n", 99 / 11);
    ft_printf("my func17:  %d\n", 3 - 9);
    printf("orig: %d\n\n", 3 - 9);
    ft_printf("my func18:  %d\n", -2.3);
    printf("orig: %d\n\n", -2.3);
    ft_printf("my func19:  %d\n", 2 * 3);
    printf("orig: %d\n\n", 2 * 3);
    ft_printf("my func20:  %d\n", 0004);
    printf("orig: %d\n\n", 0004);


	printf("\n\nlld tests : \n\n");

	// lld tests

	printf("orig:  %lld\n", 4);
    ft_printf("my func 1:  %lld\n", 4);
    printf("orig:  %lld\n", 0);
    ft_printf("my func 2:  %lld\n", 0);
    printf("orig:  %lld\n", -1);
    ft_printf("my func 3:  %lld\n", -1);
    printf("orig:  %lld\n", 10);
    ft_printf("my func 4:  %lld\n", 10);
    printf("orig:  %lld\n", 256);
    ft_printf("my func 5:  %lld\n", 256);
    printf("orig:  %lld\n", 999);
    ft_printf("my func 6:  %lld\n", 999);
    printf("orig:  %lld\n", -999);
    ft_printf("my func 7:  %lld\n", -999);
    printf("orig:  %lld\n", 9999);
    ft_printf("my func 8:  %lld\n", 9999);
    printf("orig:  %lld\n", -9999);
    ft_printf("my func 9:  %lld\n", -9999);
    printf("orig:  %lld\n", 9999999999);
    ft_printf("my func 10:  %lld\n", 9999999999);
    printf("orig:  %lld\n", 2147483647);
    ft_printf("my func 11:  %lld\n", 2147483647);
    printf("orig:  %lld\n", -2147483647);
    ft_printf("my func 12:  %lld\n", -2147483647);
    printf("orig:  %lld\n", 9223372036854775807);
    ft_printf("my func 13:  %lld\n", 9223372036854775807);
    printf("orig:  %lld\n", -9223372036854775807);
    ft_printf("my func 14:  %lld\n", -9223372036854775807);
    printf("orig:  %lld\n", NULL);
    ft_printf("my func 15:  %lld\n", NULL);
    printf("orig:  %lld\n", 'c');
    ft_printf("my func 16:  %lld\n", 'c');
    printf("orig:  %lld\n", 4 + 4);
    ft_printf("my func 17:  %lld\n", 4 + 4);
    printf("orig:  %lld\n", 4 * 4);
    ft_printf("my func 18:  %lld\n", 4 * 4);
    printf("orig:  %lld\n", 2.3);
    ft_printf("my func 19:  %lld\n", 2.3);
    printf("orig:  %lld\n", 1.0);
    ft_printf("my func 20:  %lld\n", 1.0);
    printf("orig:  %lld\n", -2.3);
    ft_printf("my func 21:  %lld\n", -2.3);
    printf("orig:  %lld\n", -1.0);
    ft_printf("my func 22:  %lld\n", -1.0);
    printf("orig:  %lld\n", 0004);
    ft_printf("my func 23:  %lld\n", 0004);
    printf("orig:  %lld\n", -0004);
    ft_printf("my func 24:  %lld\n", -0004);



	printf("\n\nhhd tests : \n\n");

	   // %hhd   tests;
    printf("d tests : \n\n");
	ft_printf("my func1:  %hhd\n", 4);
    printf("orig:  %hhd\n", 4);
    ft_printf("my func2:  %hhd\n", 99999);
    printf("orig:  %hhd\n", 99999);
    ft_printf("my func3:  %hhd\n", -99999);
    printf("orig:  %hhd\n", -99999);
    ft_printf("my func4:  %hhd\n", -1);
    printf("orig:  %hhd\n", -1);
    ft_printf("my func5:  %hhd\n", "dfdf");
    printf("orig:  %hhd\n", "dfdf");
    ft_printf("my func6:  %hhd\n", 0);
    printf("orig:  %hhd\n", 0);
    ft_printf("my func7:  %hhd\n", 9999999999);
    printf("orig:  %hhd\n", 9999999999);
    ft_printf("my func8:  %hhd\n", 2.984);
    printf("orig:  %hhd\n", 2.984);
    ft_printf("my func9:  %hhd\n", 3,44);
    printf("orig:  %hhd\n", 3,44);
    ft_printf("my func10:  %hhd\n", -999999999);
    printf("orig:  %hhd\n", -999999999);
    ft_printf("my func11:  %hhd\n", 232323);
    printf("orig:  %hhd\n", 232323);
    ft_printf("my func12:  %hhd\n", 0.5);
    printf("orig:  %hhd\n", 0.5);
    ft_printf("my func13:  %hhd\n", 'c');
    printf("orig:  %hhd\n", 'c');
    ft_printf("my func14:  %hhd\n", NULL);
    printf("orig:  %hhd\n", NULL);
    ft_printf("my func15:  %hhd\n", 2 + 3);
    printf("orig:  %hhd\n", 2 + 3);
    ft_printf("my func16:  %hhd\n", 99 / 11);
    printf("orig:  %hhd\n", 99 / 11);
    ft_printf("my func17:  %hhd\n", 3 - 9);
    printf("orig:  %hhd\n", 3 - 9);
    ft_printf("my func18:  %hhd\n", -2.3);
    printf("orig:  %hhd\n", -2.3);
    ft_printf("my func19:  %hhd\n", 2 * 3);
    printf("orig:  %hhd\n", 2 * 3);
    ft_printf("my func20:  %hhd\n", 0004);
    printf("orig:  %hhd\n", 0004);


	
	// %hd tests
	printf("hd tests:\n\n")
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