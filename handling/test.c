/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:54:16 by nparker           #+#    #+#             */
/*   Updated: 2019/03/22 15:00:05 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../other/libft/libft.h"

char		*ft_plus_first(int nb)
{
	char*	str;
	char*	temp;

    str = (char*)malloc(sizeof(char) * ft_count_digits(nb) + 2);
	temp = ft_itoa(nb);
	str[0] = '+';
	ft_strcat(str, temp);
	return (str);
}

int main()
{
	int i = 0;
	printf("%s", ft_plus_first(i));
}