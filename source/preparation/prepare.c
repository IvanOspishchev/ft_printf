/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:28:44 by nparker           #+#    #+#             */
/*   Updated: 2019/04/20 16:28:45 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void prepare_item_flags(t_fs *form_string)
{
	if (ft_strchr(form_string->flags, ' ') && ft_strchr(form_string->flags, '+'))
		ft_sym_del(&form_string->flags, ' ');
	if (ft_strchr(form_string->flags, '+') && !ft_strchr("idf", form_string->type))
		ft_sym_del(&form_string->flags, '+');
	if (ft_strchr(form_string->flags, '-') && form_string->width == 0)
		ft_sym_del(&form_string->flags, '-');
	if (ft_strchr(form_string->flags, '0') && (ft_strchr(form_string->flags, '-')))
		ft_sym_del(&form_string->flags, '0');
	if (ft_strchr(form_string->flags, '#') && !ft_strchr("xoX", form_string->type))
		ft_sym_del(&form_string->flags, '#'); 
}

void prepare_item_precision(t_fs *form_string)
{
	if (ft_strchr("c%", form_string->type))
		form_string->precision = 0;
}

void prepare_item_size_n(t_fs *form_string)
{
	char *new_str;

	new_str = NULL;
	if (ft_strncmp(form_string->size, "ll", 2) == 0)
		new_str = ft_strdup("ll");
	else if (ft_strncmp(form_string->size, "l", 1) == 0)
		new_str = ft_strdup("l");
	else if (ft_strncmp(form_string->size, "hh", 2) == 0)
		new_str = ft_strdup("hh");
	else if (ft_strncmp(form_string->size, "h", 1) == 0)
		new_str = ft_strdup("h");
	ft_strdel(&form_string->size);
	form_string->size = new_str;
}

void prepare_item_size_f(t_fs *form_string)
{
	char *new_str;

	new_str = NULL;
	if (ft_strncmp(form_string->size, "l", 1) == 0)
		new_str = ft_strdup("l");
	else if (ft_strncmp(form_string->size, "L", 1) == 0)
		new_str = ft_strdup("L");
	ft_strdel(&form_string->size);
	form_string->size = new_str;
}

void prepare_item_size(t_fs *form_string)
{
	int i;
	char *new_size;

	new_size = NULL;
	if (form_string->size == NULL)
		return ;
	if (!ft_strchr("diouxXf", form_string->type))
	{
		ft_strdel(&form_string->size);
		return ;
	}
	if (ft_strchr("diouxX", form_string->type))
		prepare_item_size_n(form_string);
	else
		prepare_item_size_f(form_string);
}

void prepare_item(t_fs *form_string)
{
	prepare_item_flags(form_string);
	prepare_item_precision(form_string);
	prepare_item_size(form_string);
}

void prepare(t_fs_vector *form_strings)
{
	int i;

	i = 0;
	while (i < fs_vector_length(form_strings))
		prepare_item(&form_strings->data[i++]);
}
