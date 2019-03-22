#include <stdio.h>

int main(void)
{
	printf("%+-d\n", 4);
	printf("%+-i\n", 4);
	printf("%+-o\n", 4);
	printf("%+-u\n", 4);
	printf("%+-x\n", 4);
	printf("%+-X\n", 4);
	printf("%+-p\n", 4);
	printf("%+-c\n", 65);
	printf("%+-f\n", 4.4);
	printf("%+-%\n");
	printf("%+-s\n", "sadf");
	
	printf("% -d\n", 4);
	printf("%05i\n", 4);
	printf("%05o\n", 4);
	printf("%05u\n", 4);
	printf("%05x\n", 4);
	printf("%05X\n", 4);
	printf("%05p\n", 4);
	printf("%05c\n", 65);
	printf("%05s\n", "he");
	printf("%05.2f\n", 4.4);
	printf("%05%\n");

	printf("%-d\n", -4);
	printf("%-i\n", -4);
	printf("%-o\n", -4);
	printf("%-u\n", -4);
	printf("%-x\n", -4);
	printf("%-X\n", -4);
	printf("%-p\n", -4);
	printf("%-c\n", -65);
	printf("%-f\n", -4.4);
	printf("%-%\n");
	printf("%-s\n", "sadf");
}
