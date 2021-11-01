#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int checkCoincidence(vector<char>& s1, vector<char>& s2) {
	int L = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) {
			L++;
		}
	}
	return L;
}

int main() {
	ifstream in("in1.txt");
	ofstream out("res.txt");
	vector<char> s1;
	vector<char> s2;
	int G = 0;
	while (in.peek() != '\n') { //reading first line
		char c;
		in >> c; 
		s1.push_back(c);
	}
	while (in.peek() != EOF) { //reading second line and search
		char c;
		in >> c;
		s2.push_back(c);
		if (s2.size() == s1.size()) {
			G += checkCoincidence(s1, s2);
			s2.erase(s2.begin());
		}
	}
	cout << "G = " << G << endl;
	out << G;
	in.close();
	out.close();
} 