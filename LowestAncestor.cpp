/*
 * Find lowest common ancestor of two 
 * nodes in a binary tree iteratively.
 */
#include <iostream>
#include <stack>

using namespace std;
struct Node {
	Node *left;
	Node *right;
	bool visited;
	int value;
};
Node* LowestComAncestor(Node* pRoot, Node* pNode1, Node* pNode2)
{
	stack<Node*> NodeStack;
	vector<Node*> PathForNode1;
	vector<Node*> PathForNode2;

	if (pRoot == NULL || pNode1 == NULL || pNode == NULL)
		return NULL;

	Node* pCurrent;
	NodeStack.push(pRoot);
	bool flag = false;
	while (!NodeStack.empty()) {
		pCurrent = NodeStack.top();
		NodeStack.pop();
		pCurrent->visited = true;
		PathForNode1.push_back(pCurrent);
		if (pCurrent == pNode1) {
			flag = true;
			break;
		}
		 if (pCurrent->right == NULL && pCurrent->left == NULL) {
			Node *temp;
			while (true) {
				temp = PathForNode1.back();
				if (temp->visited)
					PathForNode1.pop_back();
				else
					break;
			}
		}
		if (pCurrent->right)
			NodeStack.push(pCurrent->right);	
		if (pCurrent->left)
			NodeStack.push(pCurrent->left);

	}

	if (!flag)
		return NULL;
	flag = false;
	while (!NodeStack.empty())
		NodeStack.pop();
	clear_all_visited(pRoot);

}
