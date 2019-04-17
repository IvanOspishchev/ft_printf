/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:37:36 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/04 18:13:33 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *get_flags(char **str)
{
	int states[5];
	char *flags;
	char *temp;

	flags = NULL;
	arr_zero(states, 5);
	while (**str && (**str == '+' || **str == '-' || **str == '0' || **str == '#' || **str == ' '))
	{
		temp = *str;
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
		*str = ft_strdup(temp + 1);
		ft_strdel(&temp);
	}
	return (flags);
}
