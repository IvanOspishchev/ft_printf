#include "../ft_printf.h"

void fs_vector_print(t_fs_vector *v);

int main(void)
{
	t_fs		fs;
	t_fs_vector v;

	fs.flags		= "+0";
	fs.width		= 7;
	fs.precision	= 3;
	fs.size			= "ll";
	fs.type			= 'f';

	v = fs_vector_create(3);
	for (int i = 0; i < 10; ++i) {
		
		fs_vector_push_back(&v, fs);
	}
	fs_vector_print(&v);
	return (0);
}
