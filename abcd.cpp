#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
using namespace std;

void ax(int b)
{
	if (b < 5)
		throw out_of_range("fucking shit off\n");
}


int main(int argn, char *argv[])
{
	int a = atoi(argv[1]);

	try {
		ax(a);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	return 0;
}
