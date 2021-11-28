#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

bool isSign(char c) {
	vector<char> signs = {'+', '-', '*', '/'};
	for (int i = 0; i < signs.size(); i++) {
		if (c == signs[i]) {
			return true;
		}
	}
	return false;
}

bool check(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (((s[i] < '0' || s[i] > '9') && (!isSign(s[i]))) ||
			(isSign(s[i]) && (i == 0 || i != 0 && isSign(s[i - 1]) || i == s.size() - 1))) {
				return false;
			}
	} 
	return true;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	string s;
	for (int i = 0; i < T; i++) {
		in >> s;
		if (check(s)) {
			out << "DA" << endl;
		}
		else {
			out << "NU" << endl;
		}
	}
	
	in.close();
	out.close();
}