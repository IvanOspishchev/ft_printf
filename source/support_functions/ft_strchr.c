/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:06 by nparker           #+#    #+#             */
/*   Updated: 2019/04/20 16:34:03 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	while (++i < (int)ft_strlen(s) + 1)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}
