#include <stdio.h>
#include "../../support_functions/support_functions.h"

void substr_insert(char **substr, long long arg)
{
	*substr = ft_strdup(ft_ltoa(arg));
}

int main(void)
{
	char *substr;

	substr = NULL;
	substr_insert(&substr, 4252345234534);
	printf("%s", substr);
}
