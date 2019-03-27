#include <stdio.h>
#include "../../preparation/prepare.h"
#include "../../fs_vector/fs_vector.h"

int main(void)
{
	t_fs form_string;

	form_string.flags = ft_strdup(" -#+0");
	form_string.width = 34;
	form_string.precision = 23;
	form_string.size = ft_strdup("Lll");
	form_string.type = 's';

	prepare_item(&form_string);
	printf("%s::%d::%d::%s::%c\n", form_string.flags, form_string.width, form_string.precision, form_string.size, form_string.type);
	return (0);
}
