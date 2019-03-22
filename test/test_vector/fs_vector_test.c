#include "../../fs_vector/fs_vector.h"
#include <stdio.h>

int main(void)
{
    t_fs        form_string;
    t_fs_vector vector;

    form_string.flags = "+-0";
    form_string.width = 43;
    form_string.precision = 8;
    form_string.size = "ll";
    form_string.type = 'd';

    vector = fs_vector_create(1);
    for (int i = 0; i < 100; ++i) {
        fs_vector_push_back(&vector, form_string);
    }
    vector_print(&vector);
    return (0);
}
