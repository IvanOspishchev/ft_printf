#include <stdio.h>
#include "../libft/libft.h"
#include <stdlib.h>

int main(void)
{
	short		a = 8;
	int			c = -140;
	long		d = 123341341234;
	long long 	e = 123341341234;
	char g = 65;

	printf("%################3o\n", a);
	printf("%+++++++++d\n", a);
	printf("%#+d\n", a);
	printf("%+#d\n", a);
	printf("%++++++##########o\n", a);
	printf("%##########++++++++++d\n", a);
	printf("%-d\n", a);
	printf("%+++++++++#########+++++++++#########d\n", a);


	printf("%---------d\n", c);
	printf("%---+++-----d\n", c);
	printf("%---------++d\n", c);
	printf("%+--------d\n", c);
	printf("%+d\n", c);



	printf("%          d\n", a);
	printf("%        +d\n", a);
	printf("%            -d\n", a);
	printf("%######         +o\n", a);
	printf("%##########++++++++++d\n", a);
	printf("%##########++++++++++d\n", a);
	printf("%##########++++++++++d\n", a);
	printf("%##########++++++++++d\n", a);
	
	printf("%5d\n", a);
	printf("%0000d\n", a);
	printf("%00++d\n", a);
	printf("%--00d\n", a);

	printf("%\n");
	printf("%0+-# ");
	printf("%58.4");
	printf("%0+#05");
	printf("%0+#05llll");
	printf("%      0+# 05llld\n", e);
	printf("%              0+# 05lld\n", e);
	printf("%      0+# 05lllllllllllllllllllllllld\n", e);
	printf("%      0+# 05lllhhhhhhhhhhhhhhhhhhhhd\n", e);
	printf("%      0+# 05hhhhhhhhhhhhhhhhhhhhd\n", e);


	printf("");
	printf("%c\n", d);
	printf("%Lf\n", d);

	printf("\n%.0001f\n", 34.56789565);


	printf("%Lllhd\n", 66000);

	return (0);	
} 	
