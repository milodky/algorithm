#include <deque>
#include <string>
#include <iostream>
using namespace std;

struct Node {
	char c;
	int Position;
};

bool IsInside(deque<Node*> dq, char c)
{
	if (dq.front()->c == c)
		return true;
	if (dq.back()->c == c)
		return true;
	return false;
}


string GetTwoUnique(string &Str)
{
	string Ret;
	int Size = Str.size();
	if (Size == 0 || Size == 1)
		return Ret;
	bool flag = true;
	for (int i = 1; i < Size; i++) {
		if (Str[i] != Str[0]) {
			flag = false;
			break;
		}
	}

	if (flag)
		return Ret;

	deque<Node *> hashmap;
	int HistoryPosition = 0;
	int HistoryLength = 0;
	int Length = 0;
	int Position = 0;

	for (int i = 0; i < Size; i++) {
		if (hashmap.size() == 1 && Str[i] == hashmap.front()->c) {
			Length++;
			continue;
		}
		if (hashmap.size() < 2) {
			Length++;
			Node *temp  = new Node;
			temp->c = Str[i];
			temp->Position = i;
			hashmap.push_back(temp);
			continue;
		}
		if (IsInside(hashmap, Str[i])) {
		// we need to update the stored information
			if (hashmap.back()->c != Str[i]) {
				Node *front = hashmap.front();
				Node *back = hashmap.back();

				front->c = back->c;
				back->c = Str[i];
				front->Position = back->Position;
				back->Position = i;
			}
			Length++;
			continue;
		}
		Node* front = hashmap.front();
		Node* back = hashmap.back();
		if (Length > HistoryLength) {
			// update
			HistoryLength = Length;
			HistoryPosition = Position;
			Position = back->Position;
			Length = i - Position + 1;
		}
		hashmap.pop_front();

		front->c = Str[i];
		front->Position = i;
		hashmap.push_back(front);
	}
	if (HistoryLength > Length) {
		Length = HistoryLength;
		Position = HistoryPosition;
	}

	Ret = Str.substr(Position, Length);
	return Ret;
}

int main(int argn, char **argv)
{
	string str = string(argv[1]);
	cout << str << endl;

	string ret = GetTwoUnique(str);
	cout << ret << endl;
	return 0;
}
