#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ifstream in("in3.txt");
	ofstream out("res.txt");
	vector<int> letters;
	int G = 0;
	string s1;
	in >> s1;
	string s2;
	in >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	for (char c = 'a'; c < 'z'; c++) {
		letters.push_back(0);
	}
	
	for (int i = 0; i < len2; i++) {
		if (i < len1) {
			letters[s1[i] - 'a']++;
		}
		G += letters[s2[i] - 'a'];
		if (i >= len2 - len1) {
			letters[s1[len1 - len2 + i] - 'a']--;
		}
		cout << i << " " << letters[0] << " " << letters[1] << " " << G << endl;
	}
	
	cout << "G = " << G << endl;
	out << G;
	in.close();
	out.close();
} 