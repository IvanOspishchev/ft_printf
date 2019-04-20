/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:03:10 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/20 16:31:07 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


// char* ft_dec_to_bin(int n) 
// { 
//     char bin[]; 
  
//     int i = 0; 
//     while (n > 0) { 
  
//         binaryNum[i] = n % 2; 
//         n = n / 2; 
//         i++; 
//     }
// }
// char *ft_bin_to_hex(char *bin, int len)
// {
// 	char   *out;
// 	size_t  i;

// 	if (bin == NULL || len == 0)
// 		return NULL;

// 	out = malloc(len*2+1);
// 	for (i=0; i<len; i++) {
// 		out[i*2]   = "0123456789ABCDEF"[bin[i] >> 4];
// 		out[i*2+1] = "0123456789ABCDEF"[bin[i] & 0x0F];
// 	}
// 	out[len*2] = '\0';

// 	return out;
// }

// char *ft_negative_dec_to_hex(long long n)
// {
//     char *bin;

//     bin = 
// }

char		*ft_dec_to_hex(unsigned long long n)
{
	char	str[100];
	int		temp;
	int		i;
	char	*res;

	i = 0;
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			str[i++] = temp + 48;
		else
			str[i++] = temp + 87;
		n = n / 16;
	}
	str[i] = '\0';
	res = ft_rev_str(str);
	return (res);
}

// int main()
// {
//     printf("%s\n", ft_dec_to_hex(0));

// }