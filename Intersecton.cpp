class Node {
public:
	Node* next;
	int value;
};

Node* Intersection(Node *pHeadA, Node *pHeadB)
{
	int LenA = 0;
	int LenB = 0;
	int diff;
	Node* result = NULL;
	Node* TempA = pHeadA;
	Node* TempB = pHeadB;
	if (pHeadA == NULL || pHeadB == NULL)
		return result;
	while (TempA != NULL) {
		LenA++;
		TempA = TempA->next;
	}
	while (TempB != NULL) {
		LenB++;
		TempB = TempB->next;
	}
	TempA = pHeadA;
	TempB = pHeadB;
	if (LenA > LenB) {
		diff = LenA - LenB;
		while (diff) {
			TempA = TempB->next;
			diff--;
		}
	} else {
		diff = LenB - LenA;
		while (diff--)
			tempB = TempB->next;
	}
	while (tempB != NULL && tempA != NULL) {
		if (tempB == tempA) {
			result = tempB;
			break;
		}
		tempB = tempB->next;
		tempA = tempA->next;
	}
	return result;
}
