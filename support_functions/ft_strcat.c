/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:28:21 by nparker           #+#    #+#             */
/*   Updated: 2019/03/23 12:08:28 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "support_functions.h"

char			*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int			i;
	int			j;

	i = -1;
	j = (int)ft_strlen(s1);
	while (s2[++i])
		s1[j++] = s2[i];
	s1[j] = '\0';
	return (s1);
}
