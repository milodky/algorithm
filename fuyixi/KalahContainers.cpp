#include "KalahContainers.h"

void KalahContainers::init(vector<int> &Houses)
{
	int InitVal = 30;
	for (int i = 0; i < Length; i++) {
		if ((i == Length - 1) && InitVal > 0) {
			Houses[i] = InitVal;
			return;
		}
		if (InitVal > 0) {
			double R;
			int n;
			do {
				R = rand() / (double) MAX;
				n = (int) (R * (InitVal + 1));
				//cout << n << endl;
				//cout << InitVal << endl;
				//cout << "-----" << endl;
			} while (n > InitVal);
			Houses[i] = n;
			InitVal -= n;
		} else
			Houses[i] = 0;
	}
	Houses[Length] = 0;
}
void KalahContainers::Output()
	{
		cout << "############################################" << endl;
		for (int i = Length - 1; i >= 0; i--)
			cout << i + 1 << "\t";
		cout << endl << endl;
		cout << "************ Houses of Computer ************" << endl;
		for (int i = 0; i < Length; i++)
			cout << ComputerHouses[i] << "\t";
		cout << endl << endl;
		cout << "############################################" << endl;
		cout << "############################################" << endl;
		cout << endl;
		cout << "############################################" << endl;
		for (int i = 0; i < Length; i++)
			cout << i + 1 << "\t";
		cout << endl << endl;
		cout << "@@@@@@@@@@@@ Houeses of Player @@@@@@@@@@@@@" << endl;
		for (int i = 0; i < Length; i++)
			cout << PlayerHouses[i] << "\t";
		cout << endl << endl;

		cout << "Store of the Player: " <<
			PlayerHouses[Length] << endl << endl;
		cout << "Store of the Computer: " <<
			ComputerHouses[Length] << endl << endl << endl;
	}
int KalahContainers::PlayerMove(int Nth)
{
	if (Nth > Length || Nth < 1)
		return INVALID_INPUT;
	Nth--;
	int &SeedNum = PlayerHouses[Nth];
	if (SeedNum == 0)
		return INVALID_INPUT;
	int Position = Nth + 1;
	while (true) {
		for (int i = Position; i < Length; i++) {
			SeedNum--;
			PlayerHouses[i]++;
			if (SeedNum == 0) {
				// should be return;
				// break;
				return EXCHANGE;
			}
		}
		SeedNum--;
		PlayerHouses[Length]++;
		if (SeedNum == 0) {
			// should be return
			// break;
			return GOOD_LUCK;
		}
		Position = Length - 1;

		for (int i = Position; i >= 0; i--) {
			SeedNum--;
			ComputerHouses[i]++;
			if (SeedNum == 0) {
				// should be return
				// break;
				return EXCHANGE;
			}
		}
		Position = 0;
	}
	return IMPOSSIBLE;
}



int KalahContainers::ComputerMove(int Nth)
{
	if (Nth > Length || Nth < 1)
		return INVALID_INPUT;
	Nth--;
	int &SeedNum = ComputerHouses[Nth];
	if (SeedNum == 0)
		return INVALID_INPUT;
	int Position = Nth - 1;
	while (true) {
		for (int i = Position; i >= 0; i--) {
			SeedNum--;
			ComputerHouses[i]++;
			if (SeedNum == 0)
				return EXCHANGE;
		}
		SeedNum--;
		if (SeedNum == 0)
			return GOOD_LUCK;
		ComputerHouses[Length]++;
		Position = 0;
		for (int i = Position; i < Length; i++) {
			SeedNum--;
			PlayerHouses[i]++;
			if (SeedNum == 0)
				return EXCHANGE;
		}

		Position = Length - 1;
	}
	return IMPOSSIBLE;
}

void KalahContainers::KeepMoving()
{
	while (true) {
		int Num;
		int RetVal;
		do {
			Output();
			cout << "Determine the house number(1 ~ 6): ";
			cin >> Num;
			RetVal = PlayerMove(Num);
			if (RetVal == INVALID_INPUT)
				cout << "Invalid number detected! Do it again!\n";
		} while (RetVal == GOOD_LUCK || RetVal == INVALID_INPUT);
		if (IsOver(PlayerHouses))
			return;
		do {
			Num = ComputerThinking();
			cout << "Computer takes the " <<Length - Num + 1 << "th house!\n";
			RetVal = ComputerMove(Num);
		} while (RetVal == GOOD_LUCK || RetVal == INVALID_INPUT);
		if (IsOver(ComputerHouses))
			return;
		
	}
}

int KalahContainers::ComputerThinking()
{
	int Num = rand() % Length + 1;
	return Num;
}

void KalahContainers::GameStart()
{
	KeepMoving();
	Output();
	WhoIsWinner();
}

int main() {
	srand(time(NULL));
	KalahContainers A;
	A.GameStart();
	return 0;
}
