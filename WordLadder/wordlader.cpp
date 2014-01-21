#include <iostream>
#include <cstddef>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;


bool IsNeighbor(const string &word, const string &start)
{
	int Size = word.size();
	int diff = 0;
	for (int i = 0; i < Size; i++) {
		if (word[i] == start[i])
			continue;
		diff++;
		if (diff > 1)
			return false;
	}
	if (diff == 0)
		return false;
	return true;
}
bool NextWord(const string &father, string &word, size_t &i)
{
	if ((i == father.size()) && father == word)
		return true;

	if (word == "") {
		word = father;
		word[0] = (father[0] + 1 - 'a') % 26 + 'a';
		return false;
	}
	word[i] = (word[i] + 1 - 'a') % 26 + 'a';
	if (word[i] == father[i]) {
		i++;
		return NextWord(father, word, i);
	}
	return false;
}
int ladderLength(string start, string end, unordered_set<string> &dict)
{
	// Note: The Solution object is instantiated only once and is reused by each test case.
	queue<string> bfs;
	unordered_map<string, int> distance;
	unordered_map<string, string> father;
	unordered_set<string> used;

	bfs.push(start);
	used.insert(start);

	while (bfs.size() != 0) {
		const string &GodFather = bfs.front();

		string word = "";
		bool flag = false;
		size_t Pos = 0;
		//for (const auto &word : dict)

		while (true) {

			flag = NextWord(GodFather, word, Pos);
			cout << word << endl;
			if (flag == true)
				break;
			if (dict.count(word) == 0)
				continue;

			if (used.count(word) || IsNeighbor(word, GodFather) == false)
				continue;
			father[word] = GodFather;
			int dist = distance[GodFather];
			distance[word] = dist + 1;
			if (word == end)
				return (distance[word] + 1);
			used.insert(word);
			bfs.push(word);
		}
		bfs.pop();
	}
	if (distance[end] != 0)
		return (distance[end] + 1);
	return 0;
}
int main()
{
	unordered_set<string> dict;
	dict.insert("dog");
	dict.insert("hot");
	dict.insert("hog");
	dict.insert("dot");
	cout << ladderLength("dog", "hot", dict) << endl;
}





