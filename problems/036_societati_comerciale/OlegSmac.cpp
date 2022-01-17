#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int N;
		long L;
		in >> N >> L;
		vector<long> c;
		long num;
		for (int j = 0; j < N; j++) {
			in >> num;
			c.push_back(num);
		}
		sort(c.begin(), c.end());
		
		//solution
		int M = 0;
		long S = 0;
		for (int j = c.size() - 1; j >= 0; j--) {
			M++;
			S += c[j];
			if (S >= L) {
				break;
			}
		}
		if (S < L) {
			out << 0 << " " << 0;
		}
		else {
			out << M << " " << S;
		}
		out << endl;
	}
	
	in.close();
	out.close();
}