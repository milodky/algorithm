using namespace std;
class Node {
public:
	Node* next;
private:
	int value;
};


void DeleteNode(Node* phead, Node* pNodeCurrent)
{
	if (pNodeCurrent->next == NULL) {
		Node* pTemp = phead;
		while (pTemp->next != pNodeCurrent)
			pTemp = pTemp->next;
		delete pNodeCurrent;
		pTemp->next = NULL;
		return;
	}
	Node* pNodeNext = pNodeCurrent->next;
	pNodeCurrent->value = pNodeNext->value;
	pNodeCurrent->next = pNodeNext->next;
	delelte pNodeNext;
}
