/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:44:56 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:45:21 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_parsing.h"

void parse(char *format, t_fs_vector *form_strings)
{
	char		*str;
	char		*percent;
	t_fs		form_string;

	str = format;
	while ((percent = ft_strchr(str, '%')))
	{
		str = ++percent;
		get_fs(&str, &form_string);
		if (form_string.type != 0)
			fs_vector_push_back(form_strings, form_string);
	}
}