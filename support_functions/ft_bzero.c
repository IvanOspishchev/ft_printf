/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:53:39 by nparker           #+#    #+#             */
/*   Updated: 2019/03/23 11:45:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "support_functions.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = s;
	i = 0;
	if (!n)
		return ;
	while (i < n)
		*(ptr + i++) = 0;
}
