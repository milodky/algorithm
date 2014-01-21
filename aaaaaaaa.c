#include <stdio.h>
int main()
{
	int i = 0;
	long long abc = 1;
	for (i = 0; i < 7; i++)
		abc *= 63;
	printf("%d\n", abc);
	abc = abc % 77;
	printf("%d\n", abc);
	return 0;
}
