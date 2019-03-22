/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_vector_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:54:34 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 21:54:47 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_vector.h"

void fs_vector_destroy(t_fs_vector *v)
{
	int i;

	i = -1;
	while (++i < v->size)
		fs_destroy(&v->data[i]);
	free(v->data);
	v->data = NULL;
}
