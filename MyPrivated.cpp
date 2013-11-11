#include "MyPrivated.h"
#include <iostream>
using namespace std;

int main() {
	A a(5);
	A b;
	b.compute(a);

	cout << b.get() << endl;
	return 0;
}
