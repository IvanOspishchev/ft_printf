/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 22:44:53 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/20 16:34:50 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_strpush(char **str1, char str2)
{
	char	*new_str;
	int		len1;
	int		i;

	i = 0;
	if (*str1 != NULL)
		len1 = (int)ft_strlen(*str1);
	else
		len1 = 0;
	new_str = malloc(sizeof(char) * (len1 + 2));
	while (i < len1)
	{
		new_str[i] = (*str1)[i];
		++i;
	}
	new_str[i] = str2;
	new_str[i + 1] = '\0';
	if (*str1 != NULL)
		ft_strdel(str1);
	*str1 = new_str;
}
