#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;


//Definition for a point.
struct abcdefg {
    int x;
    int y;
    abcdefg() : x(0), y(0) {}
    abcdefg(int a, int b) : x(a), y(b) {}
};

class Solution {
	public:

		struct line {
			//ax + by + c = 0
			int gcd(int a, int b)
			{
				while (b) {
					int r = a % b;
					a = b;
					b = r;
				}
				return a;
			}
			int a;
			int b;
			int c;
			line() : a(0), b(0), c(0) {}
			line(abcdefg &p1, abcdefg &p2) {
				if (p1.x == p2.x) {
					a = 1;
					b = 0;
					c = 0 - p1.x;
					return;
				}
				if (p1.y == p2.y) {
					a = 0;
					b = 1;
					c = 0 - p1.y;
					return;
				}
				//c = (p1.y * p2.x - p2.y * p1.x) * (p1.x * p2.y - p2.x * p1.y);
				c = (p1.x * p2.y - p2.x * p1.y);
				if (c == 0) {
					if (p1.x == 0 && p1.y == 0) {
						int r = gcd(abs(p2.y), abs(p2.x));
						a = abs(p2.y) / r;
						b = abs(p2.x) / r;
						if ((p2.y > 0 && p2.x > 0) || (p2.x < 0 && p2.y < 0))
							b = 0 - b;
					} else {
						int r = gcd(abs(p1.y), abs(p1.x));
						a = abs(p1.y) / r;
						b = abs(p1.x) / r;
						if ((p1.y > 0 && p1.x > 0) || (p1.x < 0 && p1.y < 0))
							b = 0 - b;
					}
				} else {
					b = 0 - ((p1.x - p2.x));
					a = ((p1.y - p2.y));
					if ((0 < a && 0 < b && 0 < c) || (a < 0 && b < 0 && c < 0)) {
						a = abs(a);
						b = abs(b);
						c = abs(c);
						int r1 = gcd(a, b);
						int r2 = gcd(r1, c);
						a /= r2;
						b /= r2;
						c /= r2;
					} else if ((0 > a && 0 < b && 0 < c) || (a > 0 && b < 0 && c < 0)) {
						a = abs(a);
						b = abs(b);
						c = abs(c);
						int r1 = gcd(a, b);
						int r2 = gcd(r1, c);
						a /= r2;
						b /= r2;
						c /= r2;
						b = 0 - b;
						c = 0 - c;
					} else if ((0 > a && 0 > b && 0 < c) || (a > 0 && b > 0 && c < 0)) {
						a = abs(a);
						b = abs(b);
						c = abs(c);
						int r1 = gcd(a, b);
						int r2 = gcd(r1, c);
						a /= r2;
						b /= r2;
						c /= r2;
						c = 0 - c;
					} else if ((0 > a && 0 < b && 0 > c) || (a > 0 && b < 0 && c > 0)) {
						a = abs(a);
						b = abs(b);
						c = abs(c);
						int r1 = gcd(a, b);
						int r2 = gcd(r1, c);
						a /= r2;
						b /= r2;
						c /= r2;
						b = 0 - b;
					}
				}
			}
		};
		int maxabcdefgs(vector<abcdefg> &abcdefgs) {
			// IMPORTANT: Please reset any member data you declared, as
			// the same Solution instance will be reused for each test case.
			int Size = abcdefgs.size();
			if (Size == 0)
				return 0;
			if (Size == 1)
				return 1;
			unordered_map<int, unordered_map<int, unordered_map<int, int> > > lines;
			for (int i = 0; i < Size; i++) {
				unordered_map<int, unordered_map<int, unordered_map<int, int> > > lines_from_i;
				int same = 0;
				abcdefg& p1 = abcdefgs[i];
				for (int j = i + 1; j < Size; j++) {
					abcdefg& p2 = abcdefgs[j];
					if (p1.x == p2.x && p1.y == p2.y) {
						same++;
						continue;
					}
					line l(p1, p2);
					if (l.a != 80) {
						cout << l.a << ", " << l.b << ", " << l.c << endl;
						cout << p1.x << ", " << p1.y << endl;
						cout << p2.x << ", " << p2.y << endl;
						exit(0);
					}
					lines_from_i[l.a][l.b][l.c]++;
				}
				if (same) {
					if (Size == same + 1)
						return Size;
					if (lines_from_i.size() == 0) {
						for (auto &x : lines) {
							int a = x.first;
							for (auto &y : x.second) {
								int b = y.first;
								for (auto &z : y.second) {
									int c = z.first;
									int &cnt = z.second;
									if ((a * p1.x + b * p1.y + c) == 0)
										cnt += same;
								}
							}
						}
						continue;
					}
				}
				for (auto &x : lines_from_i) {
					int a = x.first;
					for (auto &y : x.second) {
						int b = y.first;
						for (auto &z : y.second) {
							int c = z.first;
							int &cnt = z.second;
							cnt += same;
							lines[a][b][c] += cnt;
						}
					}
				}

			}
			int ret = 0;
			for (auto &x : lines) {
				for (auto &y : x.second) {
					for (auto &z : y.second) {
						cout << "Line " << x.first << "x + " << y.first << "y + " << z.first << " = 0 : " << z.second << endl;
						if (z.second > ret)
							ret = z.second;
					}
				}
			}
			cout << ret  << endl;
			ret = (1 + sqrt(1 + 8 * ret)) / 2;
			return ret;
		}
};

int main()
{
	abcdefg P[] = {abcdefg(-435,-347),
			abcdefg(-435,-347),
			abcdefg(609,613),
			abcdefg(-348,-267),
			abcdefg(-174,-107),
			abcdefg(87,133),
			abcdefg(-87,-27),
			abcdefg(-609,-507),
			abcdefg(435,453),
			abcdefg(-870,-747),
			abcdefg(-783,-667),
			abcdefg(0,53),
			abcdefg(-174,-107),
			abcdefg(783,773),
			abcdefg(-261,-187),
			abcdefg(-609,-507),
			abcdefg(-261,-187),
			abcdefg(-87,-27),
			abcdefg(87,133),
			abcdefg(783,773),
			abcdefg(-783,-667),
			abcdefg(-609,-507),
			abcdefg(-435,-347),
			abcdefg(783,773),
			abcdefg(-870,-747),
			abcdefg(87,133),
			abcdefg(87,133),
			abcdefg(870,853),
			abcdefg(696,693),
			abcdefg(0,53),
			abcdefg(174,213),
			abcdefg(-783,-667),
			abcdefg(-609,-507),
			abcdefg(261,293),
			abcdefg(435,453),
			abcdefg(261,293),
			abcdefg(435,453)};
	vector<abcdefg> holder(P, P + sizeof(P) / sizeof(abcdefg));
	Solution x;
	int ret = x.maxabcdefgs(holder);
	cout << ret << endl;
	return 1;
}
