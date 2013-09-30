#include <iostream>
using namspace std;

struct node {
	int value;
	node* left;
	node* right;
};

void swap(node *Node1, node *Node2)
{
	int temp = Node1->value;
	Node1->value = Node2->value;
	Node2->value = temp;
}
node* IsCurrentCorrect(node *pRoot)
{
	if (pRoot == NULL)
		return NULL;
	node* pLeft;
	node* pRight;
	int LeftVal;
	int RightVal;
	int RootVal = pRoot->value;
	bool flag1 = true;
	bool flag2 = true;
	node* LeftResponse = NULL;
	node* RightResponse = NULL;

	if (!pRoot->left && !pRoot->right)
		return NULL;
	if (pRoot->left) {
		pLeft = pRoot->left;
		LeftVal = pLeft->value;
		if (LeftVal > RootVal)
			flag1 = false;
	}

	if (pRoot->right) {
		pRight = pRoot->right;
		RightVal = pRight->value;
		if (RightVal < pRoot)
			flag2= false;
	}

	if (flag1 == false && flag2 == false) {
		swap(pLeft, pRight);
		return NULL;
	} else if (flag1 == false) {
	/*
	 * The left child goes wrong, and therefore the 
	 * next wrong node must be in the right-child sub-tree
	 * or its ancestors' level
	 */
		RightResponse = IsCurrentCorrent(pRight);
		return RightResponse;
	} else if (flag2 == false) {
	/*
	 * The right child goes wrong, and therefore the next
	 * wrong node must be in the left-child sub-tree
	 * or its ancestors' level
	 */
		LeftResponse = IsCurrentCorrent(pLeft);
		return LeftResponse;
	} else {
	/* 
	 * At this level, everything is all right, go to the
	 * next level and check
	 */
		LeftResponse = IsCurrentCorrent(pLeft);
		RightResponse = IsCurrentCorrent(pRight);
	/*
	 * if No response, then this tree is all right, go back
	 * to its father's level
	 * else, if both of the wrong position is in the current
	 * tree swap them
	 * else, we can say for sure there is only one wrong node  
	 * return the wrong node to his father
	 */

	if (LeftResponse && RightResponse) {
		swap(LeftResponse, RightResponse);
		return NULL;
	} else if (LeftReponse)
		return LeftReponse;
	else if (RightReponse)
		return LeftReponse;
	else
		return NULL;
	}
}
