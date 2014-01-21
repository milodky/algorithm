#include "KalahContainers.h"

void KalahContainers::init(vector<int> &Houses)
{
	//Generate 6 numbers that sum up to 30
	const int Init = 30;  
	vector<int> Position(Length - 1);
	for (int i = 0; i < Length; i++) {
		if(i != Length - 1) {
			//Houses[i] = rand() % Init;
			Position[i] = rand() % (Init  + 1);
			//Init -= Houses[i];
		}
		else
			Houses[i] = Init;
	}

	sort(Position.begin(), Position.end());
	int Last = 0;
	for (int i = 0; i < Length - 1; i++) {
		Houses[i] = Position[i] - Last;
		Last = Position[i];
	}
	Houses[Length - 1] = Init - Last;
	int Sum = 0;
	for (int i = 0; i < Length; i++)
		Sum += Houses[i];

	assert(Sum == Init);
	Houses[Length] = 0;	
}
void KalahContainers::Output()
	{
		cout <<endl;
		cout << "Store of the Computer: " <<
			ComputerHouses[Length] << endl << endl;
		cout << "############################################" << endl;
		for (int i = Length - 1; i >= 0; i--)
			cout << i + 1 << "\t";
		cout << endl;
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
		cout << endl;
		cout << "@@@@@@@@@@@@ Houeses of Player @@@@@@@@@@@@@" << endl;
		for (int i = 0; i < Length; i++)
			cout << PlayerHouses[i] << "\t";
		cout << endl << endl;

		cout << "Store of the Player: " <<
			PlayerHouses[Length] << endl << endl;
		
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
			//If last seeds lands in the player store, then take the opposite side's seed to the store
				if (PlayerHouses[i] ==1){
					PlayerHouses[i] = 0;
					PlayerHouses[Length] += 1 + ComputerHouses[i];
					ComputerHouses[i] = 0;
				}
					
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
			if (SeedNum == 0){
			//If last seeds lands in the player store, then take the opposite side's seed to the store
				if (ComputerHouses[i] ==1){
					ComputerHouses[i] = 0;
					ComputerHouses[Length] += 1 + PlayerHouses[i];
					PlayerHouses[i] = 0;
				}
				return EXCHANGE;
			}
		}
		SeedNum--;
		ComputerHouses[Length]++;
		if (SeedNum == 0)
			return GOOD_LUCK;
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
		INPUT:
			cout << "Determine the house number(1 ~ 6): ";
			string StrNum;
			cin >> StrNum;
			try {
				Num = std::stoi(StrNum);
			} catch (const exception &e) {
				cout << "Non-numeric characters detected!\n";
				goto INPUT;
			}
			RetVal = PlayerMove(Num);			
			if (RetVal == INVALID_INPUT)
				cout << "Invalid number detected! Do it again!\n"<<endl;
			else{
				cout << "The player has chosen the " << Num << "th house" <<endl;
				Output();			
			}
			if (RetVal == GOOD_LUCK){				
				cout << "Good Job, You have an extra move!\n"<<endl;
			}
		} while (RetVal == GOOD_LUCK || RetVal == INVALID_INPUT);
		if (IsOver(PlayerHouses))
			return;
		do {
			cout << "############################################" << endl<<endl;
			cout << "Computer is thinking ......."<<endl<<endl;
			cout << "############################################" << endl<<endl;
		//	Num = ComputerThinking();
			Num = ComputerStrategy() + 1;
			cout << "Computer takes the " <<Length - Num + 1 << "th house!\n"<<endl;
			RetVal = ComputerMove(Num);
			
			if (RetVal == GOOD_LUCK){
				Output();
				cout << "Computer have an extra move!\n"<<endl;
			}
		} while (RetVal == GOOD_LUCK || RetVal == INVALID_INPUT);
		if (IsOver(ComputerHouses))
			return;
		
	}
}

int KalahContainers::ComputerThinking()
{
//	int Num = ComputerStrategy();
	int Num = rand() % Length;
	return Num;
}


/* The strategy:
   ---- First -----
   Analyze all house option so that select the house that will give an extra move  
   ---- Second ----
   Analyze all house option so that last seed end in an empty house thus get seeds from others (>0) (So that we can get more than 1 seeds to store)
   ---- Third -----
   Analyze all house option that will still put one but minimum seed in the opponent's house
   ---- Fourth ----
   Randomly pick one if above three is not valid

*/
int KalahContainers::ComputerStrategy()
{
	
	bool checker = false;
	// 0 index is the index of the empty house, 1 index is possible seeds I gain
	pair<int, int> Record = std::make_pair<int, int>(-1, -1);
	// First step
	for (int i = 0; i < Length; i++) {
		if (ComputerHouses[i] == 0)
			continue;
		if ((ComputerHouses[i] - (i + 1)) % 12 == 0) {
			if (Record.second >= 1 + (ComputerHouses[i] - (i + 1)) / 12)
				continue;
			Record.first = i;
			Record.second = 1 + (ComputerHouses[i] - (i + 1)) / 12;
			checker = true;
		}
	}
	if (checker)
		return Record.first;	
	// Second step
	for (int i = 0; i < Length; i++) {
		//If there is an empty house
		if(ComputerHouses[i] == 0){
			for(int j = i + 1; j < Length; j++) {
				if(ComputerHouses[j] == (j - i)){
					if (Record.second < 1 + PlayerHouses[i]){
						Record.first = j;
						Record.second = 1 + PlayerHouses[i];
						checker = true;
					}
				}
			}
			for(int j = i-1; j>=0; j--) {
				if((ComputerHouses[j] + (j - i)) == 12){
					if (Record.second < 1 + PlayerHouses[i]+ 1){
						Record.first = j;
						Record.second = 1 + PlayerHouses[i] + 1;
						checker = true;
					}
				}
			}
		}
	}

	if(checker)
		return Record.first;
	//Third step
	Record.second = 1000;
	int inOppo = 0;
	for (int i = 0; i < Length; i++) {
		if (ComputerHouses[i] == 0)
			continue;
		int &index = i;
		if((ComputerHouses[i] - index) <=7)
			inOppo = ComputerHouses[i] - 1 - index;
		else if((ComputerHouses[i] - index) <= 13)
			inOppo = 6;
		else if((ComputerHouses[i] - index) <= 19)
			inOppo = 6 + ComputerHouses[i] - 1 - index - 12;
		else if((ComputerHouses[i] - index) <= 25)
			inOppo = 12;
		else
			inOppo = 12 + ComputerHouses[i] - 1 - index - 18;
			
		if(Record.second > inOppo){
			Record.first = i;
			Record.second = inOppo;
			checker = true;
			}
	}
	if(checker)
		return Record.first;
	return ComputerThinking();
}


void KalahContainers::GameStart()
{
	KeepMoving();
	WhoIsWinner();
}

int main() {
	srand(time(NULL));
	KalahContainers A;
	A.GameStart();
	return 0;
}
