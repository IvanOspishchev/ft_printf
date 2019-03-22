/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:37:36 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 22:41:44 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_parsing.h"

char *get_flags(char **str)
{
	int states[5];
	char *flags;

	flags = NULL;
	arr_zero(states, 5);
	while (**str && (**str == '+' || **str == '-' || **str == '0' || **str == '#' || **str == ' '))
	{
		if (**str == '+' && states[0]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == '-' && states[1]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == '#' && states[2]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == ' ' && states[3]++ == 0)
			ft_strpush(&flags, **str);
		else if (**str == '0' && states[4]++ == 0)
			ft_strpush(&flags, **str);
		(*str)++;
	}
	return (flags);
}
