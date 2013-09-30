#include <stdio.h>
using namespace std;
void print()
{
	char c;
	c = getchar();
	if (c != '\n') {
		print();
		putchar(c);
	}
}

int main()
{
	print();
	printf("\n");
	return 0;
}
