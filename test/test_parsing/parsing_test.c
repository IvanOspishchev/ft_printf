#include "../../parsing/printf_parsing.h"
#include <stdio.h>

int main(void)
{
    t_fs_vector vector;
    char *str1 = ft_strdup("Hello, world %0+d%s%f%09.34s");
    char *str2 = ft_strdup("aksdf%%lksdfjl%%  % 0 + ----23.434343Lf");

    vector = fs_vector_create(1);
    parse(str1, &vector);
    printf("TEST1\n");
    vector_print(&vector);
    fs_vector_destroy(&vector);
    vector = fs_vector_create(1);
    parse(str2, &vector);
    printf("TEST2\n");
    vector_print(&vector);
    return (0);
}
