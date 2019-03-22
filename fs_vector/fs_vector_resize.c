/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:53:06 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:53:32 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_vector.h"

void fs_vector_resize(t_fs_vector *v, int new_size)
{
	int i;
	t_fs *new_data;

	i = -1;
	new_data = (t_fs *)malloc(sizeof(t_fs) * new_size);
	while (++i < v->size)
		fs_copy(&new_data[i], &v->data[i]);
	i = -1;
	
	while (++i < v->size)
		fs_destroy(&v->data[i]);
	free(v->data);
	v->data = new_data;
	v->capacity = new_size;
}
