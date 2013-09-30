#include <iostream>

bool IsBST(Node* pTree)
{
	if (pTree == NULL)
		return false;
	if (pTree->left == NULL && pTree->right == NULL)
		return true;
	if (pTree->left == NULL && IsBST(pTree->right))
		return true;
	if (IsBST(pTree->left) && pTree->right == NULL)
		return true;
	if (pTree->value > pTree->left->value && pTree->right->value > pTree->value)
		return true;
	else
		return false;
}
