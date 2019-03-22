/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:53:57 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:54:08 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_vector.h"

void fs_vector_push_back(t_fs_vector *v, t_fs elem)
{
	if (v->size == v->capacity)
		fs_vector_resize(v, v->size * 2);
	fs_copy(&v->data[v->size], &elem);
	v->size++;
}
