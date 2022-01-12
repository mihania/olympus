#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

const int MOD = 1000000007;

void print(vector<vector<int>>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			printf("%d ", v[i][j]);
		}

		printf("\n");
	}
}

int count(string& s) {
	int e = stoi(s);
	int res = 0;
	for (int i = 0; i <= e; i++) {
		bool valid = true;
		string v = to_string(i);
		for (int j = 1; j < v.size(); j++) {
			if (v[j] < v[j - 1]) {
				valid = false;
				break;
			}
		}

		if (valid) {
			// printf("valid e=%d: %d\n", e, i);
			res++;
		}
	}

	return res;
}

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
	for (int i = 0; i <= 9; i++) {
		res = (res + dp[dp.size() - N][i]) % MOD;
	}


	string expected = "";
	for (int i = 0; i < N; i++) {
		expected += "9";
	}
	
	// printf("s=%s res=%d expected=%d\n", s.c_str(), res, count(expected));

	for (int i = 0; i < N; i++) {
		int start = i == 0 ? s[i] - '0' + 1 : max(s[i - 1] - '0', s[i] - '0' + 1);
		for (int j = start; j <= 9; j++) {
			int diff = dp[dp.size() - N + i][j]; 
			// printf("i=%d j=%d diff=%d\n", i, j, diff);
			res -= diff;
		}

		if (i != 0 && s[i] < s[i - 1]) {
			break;
		}
	}

	// printf("s=%s res=%d expected=%d\n", s.c_str(), res, count(s));
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

	// print(dp);
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
      // if (i == 20)
      	out << solve(a, b) << endl;
   } 
   
   in.close();
   out.close();
   return 0;
}
