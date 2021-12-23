#include<vector>
#include<iostream>
#include<fstream>
#include<map>

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
	
	// m[i] = j : for sum i, j is the number of elements in the subset of min size.
	map<long long, long long> m;
    	m[0] = 0;
    	for (auto v : test.c) {
		vector<long long> values;
	       	for (auto it = m.begin(); it != m.end(); it++) {
			values.push_back(it->first);
		}

		for (auto i : values) {
			if (m.find(i + v) == m.end()) {
				m[i + v] = m[i] + 1;
			} else {
				m[i + v] = min(m[i + v], m[i] + 1);
			}
			
			if (i + v >= test.L) {
				test.M = m[i + v];
				test.S = i + v;
				return;
			}
			
		}
    	}

	return;
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

