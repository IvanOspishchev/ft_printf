/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:06 by nparker           #+#    #+#             */
/*   Updated: 2019/03/21 22:47:53 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "support_functions.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}