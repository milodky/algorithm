#include <isotream>

struct Node {
	int value;
	Node* next;
};
bool InsertNode(Node *pHead, Node *pNode)
{
	bool result = false;
	Node *pTemp = pHead;
	if (pHead == NULL || pNode == NULL)
		return result;
	if (pHead->value > pNode->value) {
		int temp = pNode->value;
		pNode->value = pHead->value;
		pHead->value = temp;
		pNode->next = pHead->next;
		pHead->next = pNode;
		return true;
	}

	while (pTemp->next != NULL) {
		if (pTemp->next->value > pNode->value)
			break;
		pTemp = pTemp->next;
	}
	if (pTemp->next == NULL) {
		if (pTemp->value <= pNode->value) {
			pTemp->next = pNode;
			pNode->next = NULL;
			result = true;
		}
	} else {
		pNode->next = pTemp->next;
		pTemp->next = pNode;
		result = true;
	}
	return result;
}
