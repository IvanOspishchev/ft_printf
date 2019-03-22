/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:46:29 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:55:22 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_vector.h"

void fs_copy(t_fs *new_form_string, t_fs *form_string)
{
	new_form_string->flags		= ft_strdup(form_string->flags);
	new_form_string->width		= form_string->width;
	new_form_string->precision	= form_string->precision;
	new_form_string->size		= ft_strdup(form_string->size);
	new_form_string->type		= form_string->type;
}
