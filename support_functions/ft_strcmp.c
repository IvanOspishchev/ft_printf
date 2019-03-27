/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:18 by nparker           #+#    #+#             */
/*   Updated: 2019/03/23 14:52:00 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "support_functions.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
