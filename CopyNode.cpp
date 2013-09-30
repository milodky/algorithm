#include <iostream>

struct Node {
	Node *next;
	Node *other;
};

Node* CopyLinkedList(Node *pHead)
{
	Node *pTemp = pHead;
	if (pTemp == NULL)
		return NULL;
	int Size = 0;
	while (pTemp != NULL) {
		Size++;
		pTemp = pTemp->next;
	}

	pTemp = pHead;


	for (int i = 0; i < Size; i++) {
		Node *pNode = new Node;
		pNode->next = pTemp->next;
		pNode->other = pTemp->other;
		pTemp->next = pNode;
		pTemp = pNode->next;
	}
	for (int i = 0; i < Size; i++) {
		pTemp = pTemp->next;
		pTemp->other = pTemp->other->next;
		pTemp = pTemp->next;
	}

	Node *pRet = pHead->next;
	pTemp = pHead;
	for (int i = 0; i < Size; i++) {
		pTemp->next = pTemp->next->next;
		pRet->next = pRet->next->next;
	}
	return pRet;

}
