#include <iostream>
#include <deque>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;
#define INT_MAX 0x3f3f3f3f
//string minWindow(string S, string T) {
//	// Note: The Solution object is instantiated only once and is reused by each test case.
//	if (T.size() > S.size() || (T == "" && S == ""))
//		return "";
//
//	int Size = S.size();
//	unordered_map<char, int> Hash;
//	for (int i = 0; i < T.size(); i++) {
//		Hash[T[i]]++;
//	}
//	cout << Hash.size() << endl;
//	unordered_map<char, deque<int> > T_Position;        
//	bool flag = false;
//	int j = 0;
//	deque<pair<char, int> > Hashmap;
//	for (int i = 0; i < Size; i++) {
//		if (flag == false && !Hash.count(S[i]))
//			continue;
//		flag = true;
//		if (Hash.count(S[i])) {
//			cout << S[i] << endl;
//			T_Position[S[i]].push_back(i);
//		}
//		Hashmap.push_back(make_pair<char&, int&>(S[i], i));
//
//		if (Hashmap.size() == 1)
//			continue;
//		if (Hashmap.front().first != Hashmap.back().first)
//			continue;
//		j = 1;
//
//		while (true) {
//			auto &x = Hashmap.front();
//			if (Hash.count(x.first) == 0 || (T_Position.count(x.first) && T_Position[x.first].size() > Hash[x.first])) {
//				if (T_Position.count(x.first) && T_Position[x.first].size() > Hash[x.first])
//					T_Position[x.first].pop_front();
//				Hashmap.pop_front();
//			}
//			else
//				break;
//		}
//	}
//	if (Hashmap.size() == 0)
//		return "";
//	if (j == 0) {
//		int EndP = 0;
//		for (auto &x : T_Position) {
//			if (EndP < x.second.back())
//				EndP = x.second.back();
//		}
//		int StartP = Hashmap.front().second;
//		return S.substr(StartP, EndP - StartP + 1);
//	}
//	int Start = Hashmap.front().second;
//	int End = Hashmap.back().second;
//	string ret(S.substr(Start, End - Start + 1));
//	return ret;
//}
//string minWindow(string S, string T) {
//	// Note: The Solution object is instantiated only once and is reused by each test case.
//	if (T.size() > S.size() || (T == "" && S == ""))
//		return "";
//
//	int Size = S.size();
//	unordered_map<char, int> Hash;
//	for (int i = 0; i < T.size(); i++) {
//		Hash[T[i]]++;
//	}
//	int StartPosition = 0;
//	int EndPosition = INT_MAX;
//	unordered_map<char, deque<int> > T_Position;        
//	bool flag = false;
//	int j = 0;
//	deque<pair<char, int> > Hashmap;
//	for (int i = 0; i < Size; i++) {
//		if (flag == false && !Hash.count(S[i]))
//			continue;
//		flag = true;
//		if (Hash.count(S[i]))
//			T_Position[S[i]].push_back(i);
//		Hashmap.push_back(make_pair<char&, int&>(S[i], i));
//
//		if (Hashmap.size() == 1)
//			continue;
//		if (Hashmap.front().first != Hashmap.back().first)
//			continue;
//		j = 1;
//		int aaa = INT_MAX;
//		int bbb = 0;
//		for (auto &x : T_Position) {
//			if (aaa > x.second.front())
//				aaa = x.second.front();
//			if (bbb < x.second.back())
//				bbb = x.second.back();
//			if (EndPosition - StartPosition > bbb - aaa) {
//				StartPosition = aaa;
//				EndPosition = bbb;
//			}
//		}
//
//		while (true) {
//			auto &x = Hashmap.front();
//			if (Hash.count(x.first) == 0 || (T_Position.count(x.first) && T_Position[x.first].size() > Hash[x.first])) {
//				if (T_Position.count(x.first) && T_Position[x.first].size() > Hash[x.first])
//					T_Position[x.first].pop_front();
//				Hashmap.pop_front();
//			}
//			else
//				break;
//		}
//	}
//	if (Hashmap.size() == 0)
//		return "";
//	while (true) {
//		auto &x = Hashmap.back();
//		if (Hash.count(x.first) == 0)
//			Hashmap.pop_back();
//		else
//			break;
//	}
//	if (j == 0) {
//		int EndP = 0;
//		for (auto &x : T_Position) {
//			cout << x.first << endl;
//			if (EndP < x.second.back())
//				EndP = x.second.back();
//		}
//		int StartP = Hashmap.front().second;
//		return S.substr(StartP, EndP - StartP + 1);
//	}
//	int Start = Hashmap.front().second;
//	int End = Hashmap.back().second;
//	if (End - Start > EndPosition - StartPosition) {
//		End = EndPosition;
//		Start = StartPosition;
//	}
//	string ret(S.substr(Start, End - Start + 1));
//	return ret;
//}
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (T.size() > S.size() || (T == "" && S == ""))
            return "";

        int Size = S.size();
        unordered_map<char, int> Hash;


        for (int i = 0; i < T.size(); i++) {
            Hash[T[i]]++;
        }
        unordered_map<char, int> Hash1(Hash);
        unordered_map<char, deque<int> > T_Position;        
        bool flag = false;
        int j = 0;
        int Sss = 0;
        int Eee = INT_MAX;
        bool flag2 = false;
        deque<pair<char, int> > Hashmap;
        for (int i = 0; i < Size; i++) {
            if (flag == false && !Hash.count(S[i]))
                continue;
            flag = true;
            if (Hash.count(S[i])) {
                T_Position[S[i]].push_back(i);
                if (Hash1.count(S[i])) {
                    Hash1[S[i]]--;
                    if (Hash1[S[i]] == 0)
                        Hash1.erase(S[i]);
                }
            }
            Hashmap.push_back(make_pair<char&, int&>(S[i], i));
            
            if (Hashmap.size() == 1)
                continue;
            if (Hashmap.front().first == Hashmap.back().first) {
                j = 1;
      
                while (true) {
                    auto &x = Hashmap.front();
                    const char &c = x.first;
                    if (Hash.count(c) == 0 || (T_Position.count(c) && T_Position[c].size() > Hash[c])) {
                        if (T_Position.count(x.first) && T_Position[x.first].size() > Hash[x.first])
                            T_Position[x.first].pop_front();
                        Hashmap.pop_front();
                    }
                    else
                        break;
                }
            }
            bool flag1 = true;
            for (auto & x : Hash) {
                if (T_Position.count(x.first) == 0) {
                    flag1 = false;
                    break;
                }
                if (x.second > T_Position[x.first].size()) {
                    flag1 = false;
                    break;
                }
            }
            if (flag1 == false)
                continue;
            flag2 = true;
            if (Eee - Sss > Hashmap.back().second - Hashmap.front().second) {
                Eee = Hashmap.back().second;
                Sss = Hashmap.front().second;
            }
        }
        if (Hash1.size())
            return "";
        if (Hashmap.size() == 0)
            return "";
        while (true) {
            auto &x = Hashmap.back();
            if (Hash.count(x.first) == 0)
                Hashmap.pop_back();
            else
                break;
        }
	cout << Sss << ", " << Eee << endl;
        if (j == 0) {
            int EndP = 0;
            for (auto &x : T_Position) {
                if (EndP < x.second.back())
                        EndP = x.second.back();
            }
                int StartP = Hashmap.front().second;
                return S.substr(StartP, EndP - StartP + 1);
        }
        if (flag2 == false)
            return "";
        int Start = Hashmap.front().second;
        int End = Hashmap.back().second;
	cout << Sss << ", " << Eee << endl;
        if (End - Start > Eee - Sss) {
            End = Eee;
            Start = Sss;
        }
        string ret(S.substr(Start, End - Start + 1));
        return ret;
    }
int main()
{
	string a = "AbBaBBaabBb";
	string b = "AB";
	cout << minWindow(a, b) << endl;
	return 1;
}
