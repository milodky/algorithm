/*
 * Say there is a string hllsacefgdbdfdfdffd 
 * You need to find the biggest string that 
 * has all consecutive characters Conditions 
 * consecutive string might have jungled words
 * i.e acb is also continous or bcad is also continuous
 */


#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
struct Node {
	int start_at;
	char max;
	char min;
};


bool IsInRange(Node &a, char c)
{
	if (a.max + 1 >= c && a.min - 1 <= c)
		return true;
	else
		return false;
}
void UpdateRange(Node &a, Node &b)
{
	if (a.max > b.max)
		b.max = a.max;
	if (a.min < b.min)
		b.min = a.min;
}

//void FindMaxConsecutiveSeq(const char *pStr, vector<Node> &Array)
//{
//	if (pStr == NULL)
//		return;
//	Array[0].max = *pStr;
//	Array[0].min = *pStr;
//	for (int i = 1; i < Array.size(); i++) {
//		char c = pStr[i];
//		if (IsInRange(Array[i - 1], c)) {
//			if (c == Array[i - 1].max + 1)
//				Array[i].max = c;
//			else
//				Array[i].max = Array[i - 1].max;
//			if (c == Array[i - 1].min - 1)
//				Array[i].min = c;
//			else
//				Array[i].min = Array[i - 1].min;
//			Array[i].start_at = Array[i - 1].start_at;
//			int j = Array[i - 1].start_at - 1;
//			while (j >= 0) {
//				if (IsInRange(Array[i], pStr[j])) {
//					UpdateRange(Array[j], Array[i]);
//					Array[i].start_at = Array[j].start_at;
//					j = Array[j].start_at - 1;
//				} else
//					break;
//			}
//		} else {
//			Array[i].max = c;
//			Array[i].min = c;
//			Array[i].start_at = i;
//		}
//	}
//	int start = 0;
//	int length = 0;
//	for (int i = 0; i < Array.size(); i++) {
//		cout << pStr[i] << ": " << Array[i].start_at << endl;
//		if (i - Array[i].start_at + 1 > length) {
//			start = Array[i].start_at;
//			length = i - Array[i].start_at + 1;
//		}
//	}
//	for (int i = start; i < length + start; i++)
//		putchar(pStr[i]);
//	cout << endl;
//}

struct CharNode {
	int Cnt;
	int Start;
	int End;
	CharNode() {
		Cnt = 0;
		Start = -1;
		End = -1;
	}
};

void UpdatingRange(vector<CharNode> &pArray, char Char, int Position)
{
	int Num = (int) (Char - 'a');
	pArray[Num].Cnt++;
	if (pArray[Num].Start == -1)
		pArray[Num].Start = Position;

	int flag = 0;
	int i = Num;
	int j = Num + 1;
	int min = 0x3f3f3f3f;
	while (flag != 3) {
		if (i >= 0 && ((flag & 0x01) != 1)) {
			if (pArray[i].Cnt) {
				min = min > pArray[i].Start ? pArray[i].Start : min;
				i--;
			} else {
				i++;
				flag = flag | 0x01;
			}
		} else
			flag = flag | 0x01;
		if (j < 26 && ((flag &0x02) != 2)) {
			if (pArray[j].Cnt) {
				min = min > pArray[j].Start ? pArray[j].Start : min;
				j++;
			} else {
				j--;
				flag = flag | 0x02;
			}
		} else
			flag = flag | 0x02;
	}
	cout << "min is " << min << endl;
	if (j == 26)
		j--;
	if (i == -1)
		i++;
	pArray[i].Start = min;
	pArray[j].End = Position;
}
void GetLargestRange(vector<CharNode> &Array, int &Start, int &End)
{
	int CurrentStart = 0x3f3f3f3f;
	Start = -1;

	int CurrentEnd = -1;
	End = 0;
	for (int i = 0; i < 26; i++) {
		if (Array[i].Cnt) {
			CurrentStart = CurrentStart > Array[i].Start ? Array[i].Start : CurrentStart;
			CurrentEnd = Array[i].End;
		} else {
			if (CurrentEnd - CurrentStart > End - Start) {
				Start = CurrentStart;
				End = CurrentEnd;
			}
			CurrentEnd = -1;
			CurrentStart = 0x3f3f3f3f;
		}
	}
	if (CurrentEnd - CurrentStart > End - Start) {
		Start = CurrentStart;
		End = CurrentEnd;
	}
	
}
void LongestConsecutiveString(const char *pStr)
{
	if (pStr == NULL)
		return;
	vector<CharNode> Array(26);
	int Length = strlen(pStr);
	int Start = 0;
	int End = 0;
	for (int i = 0; i < Length; i++)
		UpdatingRange(Array, pStr[i], i);
	GetLargestRange(Array, Start, End);
	if (End >= Start) {
		for (int i = Start; i <= End; i++)
			putchar(pStr[i]);
		cout << endl;
	}
}





int main(int argn, char **argv)
{
	const char *pStr = argv[1];
	int Length = strlen(pStr);

	vector<Node> NodeArray(Length);
	NodeArray[0].start_at = 0;
//	FindMaxConsecutiveSeq(pStr, NodeArray);
	LongestConsecutiveString(pStr);

	return 0;
}
