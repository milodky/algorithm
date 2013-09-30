#include <iostream>
#define WHITE 1
#define BLACK 0

struct Node {
	int Color;
	bool Selected;
	Node *left;
	Node *right;
};

int ColorNum(Node *pCurrent)
{
	if (pCurrent == NULL)
		return -1;
	if (pCurrent->left == NULL && pCurrent->right == NULL)
		if (pCurrent->Color == WHITE)
			return 1;
		else
			return 0;
	int CountLeft = 0;
	int CountRight = 0;
	if (pCurrent->left)
		CountLeft = ColorNum(pCurrent->left);
	if (pCurrent->right)
		CountRight = ColorNum(pCurrent->right);
	int CurrentCount = 0;
	if (CountLeft > CountRight) {
		CurrentCount = CountLeft;
		Current->left->Selected = true;
		Current->right->Selected = false;
	} else {
		CurrentCount = CountRight;
		Current->right->Selected = true;
		Current->left->Selected = false;
	}
	return (CurrentCount + Current->Color);
}
