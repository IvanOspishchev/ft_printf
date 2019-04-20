/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:29:21 by nparker           #+#    #+#             */
/*   Updated: 2019/04/20 16:29:22 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_string            str_create_str(char *s)
{
    t_string str;
    int len;
    int i;

    i = 0;
    len = ft_strlen(s);
    str.data = (char *)malloc(sizeof(char) * len  * 3 / 2);
    str.size = len;
    str.capacity = len * 3 / 2;

    while (i < len)
    {
        str.data[i] = s[i];
        ++i;
    }
    return (str);
}

t_string            str_create_size(int size)
{
    t_string str;

    str.data = (char *)malloc(sizeof(char) * size);
    str.size = 0;
    str.capacity = size;

    return str;
}

void                str_resize(t_string *s, int new_size)
{
    char *new_data;
	int i;

	i = -1;
	new_data = (char *)malloc(sizeof(char) * new_size);
	while (++i < s->size)
		new_data[i] = s->data[i];
	free(s->data);
	s->data = new_data;
    s->capacity = new_size;
}

void                str_pushchar(t_string *s, char c)
{
    if (s->size == s->capacity)
        str_resize(s, s->size * 2);
    s->data[s->size] = c;
    s->size++;
}

void                str_pushstr(t_string *s, char *str)
{
    int len;
    int i;

    i = -1;
    len = ft_strlen(str);
    if (s->capacity < s->size + len)
        str_resize(s, (s->size + len) * 2);
    while (++i < len)
        str_pushchar(s, str[i]);
}

int                str_len(t_string *s)
{
    return s->size;
}

void                str_destroy(t_string *s)
{
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}

void                str_print(t_string *s)
{
	write(1, s->data, s->size);
	write(1, "\n", 1);
}

void                str_rev(t_string *s)
{
    int i;
    char tmp;

    i = 0;
    while (i * 2 < str_len(s))
    {
        tmp = s->data[i];
        s->data[i] = s->data[str_len(s) - i - 1];
        s->data[str_len(s) - i - 1] = tmp;
        ++i;
    }
}

char                str_at(t_string *s, int idx)
{
    return s->data[idx];       
}