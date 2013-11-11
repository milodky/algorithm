#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if (word1 == "" && word2 == "")
		return 0;
	if (word1 == "" && word2 != "")
		return word2.size();
	if (word1 != "" && word2 == "")
		return word1.size();

	vector<vector<int> > Matrix(word1.size(), vector<int>(word2.size()));
	/*
	   Matrix[0][0] = (word2[0] != word1[0]);
	   for (int i = 1; i < word1.size(); i++) {
	   Matrix[i][0] = Matrix[i - 1][0] + 1;
	   }
	   for (int i = 1; i < word2.size(); i++)
	   Matrix[0][i] = Matrix[0][i - 1] + 1;
	 */            
	for (int i = 0; i < word1.size(); i++) {
		for (int j = 0; j < word2.size(); j++) {
			if (word1[i] == word2[j]) {
				if (i == 0 && j)
					Matrix[i][j] = Matrix[i][j - 1];
				else if (j == 0 && i)
					Matrix[i][j] = Matrix[i - 1][j];
				else if (i == 0 && j == 0)
					Matrix[0][0] = 0;
				else
					Matrix[i][j] = Matrix[i - 1][j - 1];
			} else {
				if (i == 0 && j == 0)
					Matrix[i][j] = 1;
				else if (i == 0 && j)
					Matrix[i][j] = Matrix[i][j - 1] + 1;
				else if (j == 0 && i)
					Matrix[i][j] = Matrix[i - 1][j] + 1;
				else {
					int temp = min(Matrix[i - 1][j], Matrix[i][j - 1]);
					Matrix[i][j] = min(Matrix[i - 1][j - 1], temp) + 1;
				}
			}
		}
	}
	for (int i = 0; i < word1.size(); i++) {
		for (int j = 0; j < word2.size(); j++) {
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
	return Matrix[word1.size() - 1][word2.size() - 1];

}

int main()
{
	//string a = "mart";
	//string b = "karma";
	string a = "pneumonoultramicroscopicsilicovolcanoconiosis";
	string b = "ultramicroscopically";
	cout << minDistance(a, b) << endl;
	return 0;
}
