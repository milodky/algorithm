/*
 * Remove all two zeros in the given string. 
 * Example: a3409jd00dk000d 
 * Output: a3409jddk000d 
 * Note: If there are less/more than two zeros consecutive, it should not be replaced.
 */
#include <iostream>
using namespace std;
void Remove2Zeros(char *pStr)
{
	if (pStr == NULL)
		return;
	char *pCurrent = pStr;
	char *pBase = pStr;
	int ZeroCnt = 0;
	while (*pCurrent != '\0') {
		if (*pCurrent == '0')
			ZeroCnt++;
		else {
			if (ZeroCnt == 2) {
				pBase -= ZeroCnt;
				ZeroCnt = 0;
			}
		}
		*pBase = *pCurrent;
		pBase++;
		pCurrent++;
	}
	if (ZeroCnt == 2)
		pBase -= 2;
	*pBase = '\0';
}
int main()
{
	char ChArray[20];
	cin >> ChArray;
	Remove2Zeros(ChArray);
	cout << ChArray << endl;
	return 0;
}
