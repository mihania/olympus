#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

bool smaller(string& s, int second) {
	int first = 0;
	while (second != s.size() - 1) {
		if (s[first] < s[second]) {
			return true;
		}
		else if (s[first] > s[second]) {
			return false;
		}
		first++;
		second++;
	}
	return true;
}

int solution(string& s) {
	if (s.size() == 1) {
		return 0;
	}
	int v = 0;
	for (int i = 1; i <= s.size() / 2; i++) {
		if (s[i] != '0') {
			if (s.substr(0, i).size() < s.substr(i, s.size() - 1).size() ||
				s.substr(0, i).size() == s.substr(i, s.size() - 1).size() && smaller(s, i)) { 
				v++;
			}
		}
	}
	return v;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	string s;
	for (int i = 0; i < T; i++) {
		in >> s;
		out << solution(s) << endl;
	}
	
	in.close();
	out.close();
}