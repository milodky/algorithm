#include <stdio.h>

unsigned char Add(unsigned char a, unsigned char b, unsigned char *overflow)
{

	unsigned char MyMax = a > b? a : b;

	unsigned char ret = a + b;

	if (ret < MyMax)
		*overflow = 1;
	else
		*overflow = 0;
	return ret;

		
}

int main()
{
	unsigned char a = 0xF0;
	unsigned char b = 0x11;
	unsigned char overflow = 0;

	unsigned ret = Add(a, b, &overflow);
	printf("ret = %d, overflow is %d", (int) ret, (int) overflow);
	return 0;
}
