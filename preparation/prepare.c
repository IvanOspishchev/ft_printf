#include "prepare.h"

void sym_del(char *str, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = NULL:
	while (str[i])
	{
		if (str[i] != c)
			ft_strpush(new_str, str[i]);
		++i;
	}
	free(str);
	str = new_str;
}

void prepare_item_flags(t_fs *form_string)
{
	if (ft_strchr(form_string->flags, ' ') && ft_strchr(form_string->flags, '+'))
		sym_del(form_string->flags, ' ');
	if (ft_strchr(form_string->flags, '+') && !ft_strchr("idf", form_string->type))
		sym_del(form_string->flags, '+');
	if (ft_strchr(form_string->flags, '-') && form_string->width == 0)
		sym_del(form_string->flags, '-');
	if (ft_strchr(form_string->flags, '0') && (ft_strchr(form_string->flags, '-') || form_string->width == 0))
		sym_del(form_string->flags, '0');
	if (ft_strchr(form_string->flags, '#') && !ft_strchr("", form_string->type))
		sym_del(form_string->flags, '#'); 
}

void prepare_item_precision(t_fs *form_string)
{

}

void prepare_item_size(t_fs *form_string)
{
	int i;
	char *new_size;

	new_size = NULL;
	if (!ft_strchr(form_string->type, "diouxXf"))
	{
		ft_strdel(&form_string->size);
		return ;
	}
	/* Доделать функцию до конца */
	
}

static void prepare_item(t_fs *form_string)
{
	prepare_item_flags(form_string);
	prepare_item_size(form_string);
	prepare_item_precision(form_string);
}

void prepare(t_fs_vector *form_strings)
{
	int i;

	i = 0;
	while (i < fs_vector_length(form_strings))
		prepare_item(&form_strings->data[i]);
}
