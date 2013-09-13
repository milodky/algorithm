#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;
#define Max(a, b) ((a) > (b)) ? (a) : (b)
#define Min(a, b) ((b) > (a)) ? (a) : (b)

typedef struct node {
	int distance;
	int position;
} Node;

typedef unordered_map<int, Node*> Hash_map;

void MaxDistance(int *pArray, int Num, Hash_map &MyHashMap)
{
	Hash_map::iterator Iter;
	for (int i = 0; i < Num; i++) {
		Iter = MyHashMap.find(pArray[i]);
		if (Iter == MyHashMap.end()) {
			Node *pNode = new Node;
			pNode->distance = 0;
			pNode->position = i;
			MyHashMap.insert(pair<int, Node*>(pArray[i], pNode));
		//	initialize Node information
		} else {
			Iter->second->distance = i - Iter->second->position;
		}
	}
}

int main(int argn, char **argv)
{
	int n = atoi(argv[1]);
	int *Array = new int[n];
	Hash_map TheHashMap;
	for (int i = 0; i < n; i++)
		Array[i] = rand() % 15;
	for (int i = 0; i < n; i++)
		cout << Array[i] << " ";
	cout << endl;
	MaxDistance(Array, n, TheHashMap);
	Hash_map::iterator Iter;
	for (Iter = TheHashMap.begin(); Iter != TheHashMap.end(); Iter++) {
		Node *pNode = Iter->second;
		cout << "Value = " << Iter->first << ", Distance = " << pNode->distance << endl;
		delete pNode;
	}
	delete[] Array;
	return 0;
}

