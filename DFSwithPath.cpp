/*
 * DFS a binary tree with path stored
 */

#include <stack>
#include <iostream>

stack<Node *> DfsStack;
stack<Node *> PathStack;
bool IsFound;
bool DFSwithPath(node *pNode, *node pKey)
{
	if (pNode == NULL)
		return;
	PathStack.push(pNode);
	if (pNode->value == pKey->value)
		return true;
	IsFound = DfsWithPath(pNode->left, pKey);
	if (IsFound)
		return true;
	IsFound = DfsWithPath(pNode->right, pKey);
	if (IsFound)
		return true;
	PathStack.pop();
}
