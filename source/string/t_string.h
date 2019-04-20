#ifndef T_STRING_H_
#define T_STRING_H_


typedef struct		s_string
{
	char			*data;
	int				size;
	int				capacity;
}                   t_string;

t_string            str_create_str(char *s);
t_string            str_create_size(int size);
void                str_resize(t_string *s, int new_size);
void                str_pushchar(t_string *s, char c);
void                str_pushstr(t_string *s, char *str);
int                 str_len(t_string *s);
void                str_destroy(t_string *s);
void                str_print(t_string *s);
void                str_rev(t_string *s);
char                str_at(t_string *s, int idx);

#endif