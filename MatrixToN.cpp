#include <iostream>

using namespace std;

class Matrix {
public:
	int val[2][2];
	friend Matrix operator*(Matrix &X, Matrix& Y) {
		Matrix ret;
		ret.val[0][0] = X.val[0][0] * Y.val[0][0] + X.val[0][1] * Y.val[1][0];
		ret.val[0][1] = X.val[0][0] * Y.val[0][1] + X.val[0][1] * Y.val[1][1];
		ret.val[1][0] = X.val[1][0] * Y.val[0][0] + X.val[1][1] * Y.val[1][0];
		ret.val[1][1] = X.val[1][0] * Y.val[0][1] + X.val[1][1] * Y.val[1][1];
		return ret;
	}
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		val[0][0] = a;
		val[0][1] = b;
		val[1][0] = c;
		val[1][1] = d;
	}
	friend ostream& operator << (ostream& os, const Matrix X) {
		os << X.val[0][0] << ", " << X.val[0][1] << endl;
		os << X.val[1][0] << ", " << X.val[1][1] << endl;
		return os;
	}
};


Matrix MatrixToN(Matrix& mat, int N)
{
	if (N == 1)
		return mat;
	if (N == 2)
		return mat * mat;
	bool flag = N % 2;
	Matrix ret;
	ret = MatrixToN(mat, N / 2);
	ret = ret * ret;
	if (flag)
		ret = ret * mat;
	return ret;
}


int FunNthValue(int N)
{
	int f2 = 3;
	int f1 = 1;
	if (N <= 0)
		return -1;
	if (N == 1)
		return f1;
	if (N == 2)
		return f2;
	int result = 0;
	Matrix base(2, 2, 1, 0);
	Matrix final = MatrixToN(base, N - 2);
	cout << final;
	result = f2 * final.val[0][0] + f1 * final.val[0][1];
	return result;
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	int result = FunNthValue(Num);
	cout << result << endl;
	return 0;
} 
