#include <iostream>

using namespace std;

Node* AlternateNodes(Node *pHead)
{
	Node *pTemp = pHead;
	if (pTemp == NULL)
		return NULL;
	if (pTemp->next == NULL)
		return pHead;
	int Size = 0;
	while (pTemp != NULL) {
		pTemp = pTemp->next;
		Size++;
	}
	pTemp = pHead;

	Node *pTempNext = pTemp->next;
	pTemp->next = pTempNext->next;
	pTempNext->next = pTemp;
	Node *pRet = pTempNext;

	Node *pPrevious = pTemp;
	pTemp = pTemp->next;
	int i = 2;
	while (i < Size) {
		pTempNext = pTemp->next;
		pTemp->next = pTempNext->next;
		pTempNext->next = pTemp;
		pPrevious->next = pTempNext;
		pPrevious = pTemp; 
		pTemp = pTemp->next;
		i += 2;
	}

	return pRet;
}
