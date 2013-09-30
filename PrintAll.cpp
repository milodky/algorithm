/*
 * we get two sorted arrays a[n], b[n] and a target number K,
 * find all pairs of (i, j) that satisfies K = a[i] + b[j]
 */
#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
void PrintAllV2(vector<int> &a, vector<int> &b, int i, int j, int K)
{
	if (a.empty() || b.empty())
		return;
	if (i >= a.size() || j < 0)
		return;
	if (a[i] + b[j] == K) {
		printf("a[%d] = %d, b[%d] = %d\n", i, a[i], j, b[j]);
		PrintAllV2(a, b, i + 1, j, K);
//		PrintAllV2(a, b, i, j - 1, K);
	} else if (a[i] + b[j] > K)
		PrintAllV2(a, b, i, j - 1, K);
	else
		PrintAllV2(a, b, i + 1, j, K);
		
		
		
} 
//void PrintAll(vector<int> &a, vector<int> &b, int K)
//{
//	if (a.empty() || b.empty())
//		return;
//	int SizeA = a.size();
//	int SizeB = b.size();
//
//	int i = 0;
//	int j = SizeB - 1;
//
//	while (i < SizeA && j >= 0) {
//		if (a[i] + b[j] == K) {
//			printf("a[%d] = %d, b[%d] = %d\n", i, a[i], j, b[j]);
//			i++;
//		}
//		else if (a[i] + b[j] > K)
//			j--;
//		else
//			i++;
//	}
//}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	vector<int> a(Num);
	vector<int> b(Num);
//	a.reserve(Num);
//	b.reserve(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		a[i] = rand() % Num;
	}
//	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		b[i] = rand() % Num;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < Num; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < Num; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	//PrintAll(a, b, Num / 2);
	PrintAllV2(a, b, 0, b.size() - 1, Num / 2);
	return 0;
}
