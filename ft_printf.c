/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:28:29 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/20 12:14:08 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(char *format, ...)
{
	size_t			len;
	va_list			args;
	t_fs_vector		form_strings;

	va_start(args, format);
	fs_parse(format, &form_strings)
	handler(&args, &form_strings, &format);
	len = ft_strlen(format);
	write(1, format, len);
	return ((int)len);
}
