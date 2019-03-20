/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:28:20 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/20 14:29:04 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H_
#define FT_PRINTF_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include "libft/libft.h"

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

/* Functions for t_fs_vector */
t_fs_vector		fs_vector_create(int size);
void			fs_vector_resize(t_fs_vector *v, int new_size);
void			fs_vector_push_back(t_fs_vector *v, t_fs elem);
void			fs_vector_destroy(t_fs_vector *v);
int				fs_vector_length(t_fs_vector *v);

/* Handleer functions */
void			fs_parse(char *format, t_fs_vector *form_strings);
void			d_handler(t_fs *form_string, long long arg, char **format);
void			i_handler(t_fs *form_string, long long arg, char **format);
void			o_handler(t_fs *form_string, long long arg, char **format);
void			u_handler(t_fs *form_string, long long arg, char **format);
void			x_handler(t_fs *form_string, long long arg, char **format);
void			xx_handler(t_fs *form_string, long long arg, char **format);
void			f_handler(t_fs *form_string, long double arg, char **format);
void			c_handler(t_fs *form_string, char arg, char **format);
void			s_handler(t_fs *form_string, char *arg, char **format);
void			p_handler(t_fs *form_string, long long arg, char **format);
void			pr_handler(t_fs *form_string, char args, char **format);

/* Main handler */
void			handler(va_list *args, t_fs_vector *form_strings, char **format);

/* Main function */
int				ft_printf(char *format, ...);

#endif
