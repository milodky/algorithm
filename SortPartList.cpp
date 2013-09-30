/*
 * sublist of a sorted (ascending order)link list is reversed... 
 * correct it 
 * 1--->2--->3--->4--->8--->7--->6--->5--->9--->10--->NULL
 */

struct node {
	node *next;
	int value;
};

void SortList(node *pHead)
{
	if (pHead == NULL)
		return;
	int Size = 0;
	node *Start = NULL;
	node *End = NULL;

	node *pCurrent = pHead;
	while (pCurrent->next != NULL) {
		Size++;
		node *pNext = pCurrent->next;
		if (pNext->value < pCurrent->value && Start == NULL)
			Start = pCurrent;

		if (pNext->value >= pCurrent->value && Start && End == NULL)
			End = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (Start == NULL || End == NULL)
		return;

	while (Start != End) {
		*pNode = Start->next;
		Start->next = pNode->next;
		pNode->next = End->next;
		End->next = pNode;
	}

	
}
