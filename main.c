#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int i;
	long long p;
	long double n;

	i = 4;
	printf("orig func:|%.1f|\n",  0.45);
	ft_printf("my func:  |%.1f|\n", 0.45);
}