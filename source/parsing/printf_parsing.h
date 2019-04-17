#ifndef PRINTF_PARSING_H_
#define PRINTF_PARSING_H_

#include "../fs_vector/fs_vector.h"

void    arr_zero(int *arr, int size);
char    *get_flags(char **str);
void    get_fs(char **str, t_fs *form_string);
int     get_precision(char **str);
char    *get_size(char **str);
char    get_type(char **str);
int     get_width(char **str);
int     overflow_handle(char *str);
void    parse(char *format, t_fs_vector *form_strings);

#endif