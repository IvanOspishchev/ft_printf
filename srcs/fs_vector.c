#include "../ft_printf.h"
#include <stdio.h>

void fs_copy(t_fs *new_form_string, t_fs *form_string)
{
	new_form_string->flags		= ft_strdup(form_string->flags);
	new_form_string->width		= form_string->width;
	new_form_string->precision	= form_string->precision;
	new_form_string->size		= ft_strdup(form_string->size);
	new_form_string->type		= form_string->type;
}

void fs_destroy(t_fs *form_string)
{
	ft_strdel(&form_string->flags);
	ft_strdel(&form_string->size);
}

t_fs_vector fs_vector_create(int size)
{
	t_fs_vector v;

	v.data = (t_fs *)malloc(sizeof(t_fs) * size);
	v.size = 0;
	v.capacity = size;
	return v;
}

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

void fs_vector_push_back(t_fs_vector *v, t_fs elem)
{
	if (v->size == v->capacity)
		fs_vector_resize(v, v->size * 2);
	fs_copy(&v->data[v->size], &elem);
	v->size++;
}

void fs_vector_destroy(t_fs_vector *v)
{
	int i;

	i = -1;
	while (++i < v->size)
		fs_destroy(&v->data[i]);
	free(v->data);
	v->data = NULL;
}

int fs_vector_length(t_fs_vector *v)
{
	return (v->size);
}

/* Delete in the end of project */
void fs_vector_print(t_fs_vector *v)
{
	int i;

	i = -1;
	while (++i < v->size)
		printf("%s::%d::%d::%s::%c\n", v->data[i].flags, v->data[i].width, v->data[i].precision, v->data[i].size, v->data[i].type);
}
