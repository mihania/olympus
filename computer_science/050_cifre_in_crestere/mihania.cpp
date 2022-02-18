#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

const int MOD = 1000000007;

// true if s is increasing number, otherwise false.
bool isValid(string& s) {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] < s[i - 1]) {
			return false;
		}
	}

	return true;
}

// get number of increasing numbers that are not bigger than s
int count(string& s, vector<vector<int>>& dp) {
	const int N = s.size();
	int res = 0;
	
	// getting total number of increasing numbers of length N
	for (int i = 0; i <= 9; i++) {
		res = (res + dp[dp.size() - N][i]) % MOD;
	}

	// subtracting increasing numbers of length N that are bigger than s.
	for (int i = 0; i < N; i++) {
		int start = i == 0 ? s[i] - '0' + 1 : max(s[i - 1] - '0', s[i] - '0' + 1);
		for (int j = start; j <= 9; j++) {
			int diff = dp[dp.size() - N + i][j]; 
			res -= diff;
		}

		if (i != 0 && s[i] < s[i - 1]) {

			// breaking here as rule has been violated and we can't have more numbers.
			break;
		}
	}

	return res;
}

int solve(string& a, string& b) {
	
	// dp[i][j] - number of increasing numbers of length N - i + 1 that start with j
	vector<vector<int>> dp(b.size() + 1, vector<int>(10, 0));
	for (int i = dp.size() - 1; i > 0; i--) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (i == dp.size() - 1) {
				dp[i][j] = 1;
			} else {
				for (int k = j; k < dp[0].size(); k++) {
					dp[i][j] = (dp[i][j] + dp[i + 1][k]) % MOD; 
				}
			}
		}
	}

	// check whether a is valid to not double exclude it.
	return (count(b, dp) + (isValid(a) ? 1 : 0)) % MOD - count(a, dp);
}

int main() {
   ifstream in("tests.in");
   ofstream out("tests.out");
   int T;
   in >> T;
   for (int i = 0; i < T; i++) {
      string a, b;
      in >> a >> b; 
      out << solve(a, b) << endl;
   } 
   
   in.close();
   out.close();
   return 0;
}
