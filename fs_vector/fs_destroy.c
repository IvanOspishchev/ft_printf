/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:51:30 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:51:59 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_vector.h"

void fs_destroy(t_fs *form_string)
{
	ft_strdel(&form_string->flags);
	ft_strdel(&form_string->size);
}
