#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

class Test {
public:
	long long N;
	long long L;
	vector<long long> c;	
	long long M;
	long long S;	
};

void solve(Test& test) {
	sort(test.c.begin(), test.c.end());
	test.S = 0;
	for (int i = test.c.size() - 1; i >= 0; i--) {
		test.S += test.c[i];
		if (test.S >= test.L) {
			test.M = test.c.size() - i;
			break;
		}
	}
}

int main() {
	ifstream in("tests.in");
	ofstream out("tests.out");
	long T;
	in >> T;
	for (auto t = 0; t < T; t++) {
		Test test;
		in >> test.N >> test.L;
		for (int i = 0; i < test.N; i++) {
			long long v;
			in >> v;
			test.c.push_back(v);
		}

		solve(test);
		out << test.M << " " << test.S << endl;
	}
	
	in.close();
	out.close();
}

