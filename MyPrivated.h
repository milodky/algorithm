#ifndef MYPRIVATED_H_
#define MYPRIVATED_H_

class A {
public:
	A (int m = 0) :n(m){}
	void compute(const A& x) {
		n = x.n;
	}
	int get() const {
		return n;
	}
private:
	int n;
};
#endif
