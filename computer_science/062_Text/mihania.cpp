#include<iostream>
#include<fstream>
#include<vector>

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

	// dp[i] - max length of subsequence number starting with word i
	vector<int> dp(m.size(), 1);

	// next[i] - the index of previous word of max subsequence if it starts with word i
	vector<int> next(m.size(), -1);

	// searching LIS (longest increasing subsequence)
	int maxI = 0;
	for (int i = m.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < m.size(); j++) {
			if (	// does the word start with same letter?
				m[i][m[i].length() - 1] == m[j][0]
				
				// is subsequence bigger?
				&& dp[j] + 1 > dp[i]) {

				dp[i] = dp[j] + 1;
				next[i] = j;

				if (dp[maxI] < dp[i]) {
					maxI = i;
				}
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
