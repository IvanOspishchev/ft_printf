#ifndef FS_VECTOR_H_
#define FS_VECTOR_H_

#include "../support_functions/support_functions.h"

typedef struct		s_fs {
	char			*flags;
	int				width;
	int				precision;
	char			*size;
	char			type;
}					t_fs;

typedef struct		s_fs_vector {
	t_fs			*data;
	int				size;
	int				capacity;
}					t_fs_vector;

t_fs_vector		fs_vector_create(int size);
void			fs_vector_resize(t_fs_vector *v, int new_size);
void			fs_vector_push_back(t_fs_vector *v, t_fs elem);
void			fs_vector_destroy(t_fs_vector *v);
int				fs_vector_length(t_fs_vector *v);

void			fs_copy(t_fs *new_form_string, t_fs *form_string);
void			fs_destroy(t_fs *form_string);

/* Delete this function */
void			vector_print(t_fs_vector *v);

#endif
