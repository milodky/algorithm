/*
 * Design and implement a class to generate random
 * numbers in an arbitrary probability distribution
 * given by an array of integer weights
 * 
 * i.e. for int[] w return a number, n, from
 * 0 to w.length - 1 with probability w[n] / sum(w).
 * 
 * Using an existing random number generator with
 * a uniform distribution is permitted. 
 * 
 * Example distribution: 
 * w = 1, 2, 3, 2, 1 
 * 
 * Example probabilities: 
 * w / sum = 1/9, 2/9, 1/3, 2/9, 1/9 
 */

#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <ctime>
#include <map>
#include <set>
using namespace std;

/*
 * succeeded by using map/set, uncompilable using unordered_map or unordered_set
 * clang++ -std=c++11 Name.cpp -o Name used
 */

void GenerateProbability(unordered_map<int, double> &Probability, unordered_set<int> &Numbers)
{
	int Size = Numbers.size();
	if (Size == 0)
		return;
	int Sum = 0;
	for (auto n : Numbers) {
		Sum += n;
	}
	double CumulativeP = 0;
	for (auto n : Numbers) {
		CumulativeP += (double) n / Sum;
		Probability[n] = CumulativeP;
	}
}

int GenerateNumbers(unordered_map<int, double> &Probability)
{
	double R = (double) (rand() + 1) / INT_MAX;
	double LastP = 0;
	for (auto &mypair : Probability) {
		if (LastP < R && R <= mypair.second) {
			return mypair.first;
		}
		LastP = mypair.second;
	}
	return INT_MAX;
}

int main(int argn, char **argv)
{
	int Num = atoi(argv[1]);
	unordered_set<int> Numbers;
	unordered_map<int, double> Probability;
	unordered_map<int, double> Result;
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		int n = rand() % Num + 1;
		Numbers.insert(n);
	}
	GenerateProbability(Probability, Numbers);
	

	for (auto n : Numbers) {
		Result[n] = 0;
	}		
	for (int i = 0; i < 1000; i++) {
		int n = GenerateNumbers(Probability);
		Result[n]++;
	}

	for (auto &mypair : Result) {
		cout << mypair.first << ": " << mypair.second << endl;
	}
	return 0;
}
