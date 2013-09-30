#include <iostream>

#include <vector>
#include <stack>
using std::vector;
using std::stack;
vector<Node*> MyVector;

bool Path(Node *Current, Node *pNode)
{
	bool result = false;
	if (Current == pNode)
		return true;
	if (Current->left) {
		result = Path(Current->left, pNode);
		if (result) {
			MyVector.push_back(Current);
			return result;
		}
	}
	if (Current->right) {
		result = Path(Current->right, pNode);
		if (result) {
			MyVector.push_back(Current);
			return result;
		}
	}

	return false;
		
}

