#ifndef KALAHCONTAINERS_H_
#define KALAHCONTAINERS_H_
#include <assert.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm> 
#include <stdexcept>
#include <utility>
using std::pair;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::exception;
#define EXCHANGE	0
#define INVALID_INPUT	1
#define GOOD_LUCK	2
#define IMPOSSIBLE	3

class KalahContainers {
public:
	KalahContainers() : Length(6),
			PlayerHouses(vector<int> (Length + 1)),
			ComputerHouses(vector<int> (Length + 1))
	{
		init(PlayerHouses);
		init(ComputerHouses);
	}
	
	void Output(void);

	bool IsOver(vector<int> &Vec)
	{
		for (int i = 0; i < Length; i++) {
			if (Vec[i] != 0)
				return false;
		}
		return true;
	}
	void WhoIsWinner() {
		int PlayerSum = 0;
		int ComputerSum = 0;
		for (int i = 0; i < Length + 1; i++) {
			PlayerSum += PlayerHouses[i];
			ComputerSum += ComputerHouses[i];
		}
		if (PlayerSum > ComputerSum)
			cout << "Player wins!\n";
		else if (PlayerSum == ComputerSum)
			cout << "Tie!\n";
		else
			cout << "Computer wins!\n";
	}
	
	void GameStart(void);
	void KeepMoving(void);
	
	/*
	 * Actually we can make the below two functions
	 * together and thus optimize the whole program
	 */
	int PlayerMove(int);
	int ComputerMove(int);
	void init(vector<int> &);
	
	int ComputerThinking(void);
	int ComputerStrategy(void);
	
private:
    //const int MAX;
	const int Length;
	vector<int> PlayerHouses;
	vector<int> ComputerHouses;
};




#endif
