/*
 * Convert a binary search tree into doubly linked list in sorted order in place.
 */

#include <iostream>
#define ROOT	0
#define LEFT	1
#define RIGHT	2
struct node {
	int value;
	node *left;
	node *right;
};



void BstToList(node *pNode, node **pPrev, node **pHead)
{
	if (pNode == NULL)
		return;

	BstToList(pNode->left, pPrev, pHead);

	if (*pPrev == NULL) {
		*pHead = pNode;
	} else {
		pNode->left = *pPrev;
		(*pPrev)->right = pNode;
	}
	*pPrev = pNode;
	BstToList(pNode->right, pPrev, pHead);
	
}
