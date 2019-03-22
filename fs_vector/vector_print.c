/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:56:32 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 22:25:38 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_vector.h"
#include <stdio.h>

void vector_print(t_fs_vector *v)
{
	int i;

	i = -1;
	while (++i < v->size)
		printf("%s::%d::%d::%s::%c\n", v->data[i].flags, v->data[i].width, v->data[i].precision, v->data[i].size, v->data[i].type);
}
