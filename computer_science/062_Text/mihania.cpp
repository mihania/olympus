#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
	ifstream in("tests.in");
	string word;
	vector<string> m;
	while (in >> word) {
		m.push_back(word);
	}	

	in.close();

	ofstream out("tests.out");
	out << m.size() << endl;

	// next[i] - the index of previous word of max subsequence if it starts with word i
	vector<int> next(m.size(), -1);

	// dp[i] - the max lenth of subsequence if sentense starts at word i.
	vector<int> dp(m.size(), 1);

	// mp[ch] - returns the best index in word list that starts with letter ch
	unordered_map<char, int> mp;
	
	// searching LIS (longest increasing subsequence)
	int maxI = 0;
	for (int i = m.size() - 1; i >= 0; i--) {
		
		// first letter of the word
		char fst = m[i][0];

		// last letter of the word.
		char lst = m[i][m[i].length() - 1];

		if (mp.find(fst) == mp.end()) {
			mp[fst] = i;
		}
		
		if (	// does the word exist?
			mp.find(lst) != mp.end()) {
			
			int j = mp[lst];

			if (dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				next[i] = j;
				mp[fst] = i;
			}

			if (dp[maxI] < dp[i]) {
				maxI = i;
			}
		}	
	}

	out << m.size() - dp[maxI] << endl;
	int i = maxI;
	do {
		out << m[i] << endl;
		i = next[i];
	} while (i != -1);

	out.close();
	return 0;
} 
