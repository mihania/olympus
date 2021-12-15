#include<fstream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
#include<iostream>

using namespace std;

int dppp[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 

class Test {
public:
	vector<vector<char>> z;
	vector<vector<long>> h;
	pair<int, int> P;
	long N;
};

template <typename T>
void printf(vector<vector<T>>& m) {
	for (auto& v : m) {
		for (auto k : v) {
			cout << k << " ";
		}
		
		printf("\n");
	}

	printf("\n");
}


long solve(Test& t) {
	
	// dp[i][j] - min cost to reach point (i, j) from postal office.
	vector<vector<vector<long>>> dp(t.N, vector<vector<long>>(t.N, vector<long>(3, LONG_MAX)));

	queue<tuple<int, int, long, long>> q;
	q.push({t.P.first, t.P.second, t.h[t.P.first][t.P.second], t.h[t.P.first][t.P.second]});
	dp[t.P.first][t.P.second][0] = 0;
	dp[t.P.first][t.P.second][1] = dp[t.P.first][t.P.second][2] = t.h[t.P.first][t.P.second];
	while (!q.empty()) {
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		long curMin = get<2>(q.front());
		long curMax = get<3>(q.front());
		q.pop();
		for (auto& dpp : dppp) {
			int ni = i + dpp[0];
			int nj = j + dpp[1];
			if (ni >= 0 && ni < t.N && nj >= 0 && nj < t.N) {
			
				bool updated = false;	
			 	long newMin = min(curMin, t.h[ni][nj]);
				long newMax = max(curMax, t.h[ni][nj]);
				long newCost = newMax - newMin;
				
				if (newCost < dp[ni][nj][0]) {
					dp[ni][nj][0] = newCost;
					dp[ni][nj][1] = newMin;
					dp[ni][nj][2] = newMax;
					q.push({ni, nj, newMin, newMax});
				}
			}
		}
	}

	long gMin = LONG_MAX;
	long gMax = LONG_MIN;
	for (int i = 0; i < t.N; i++) {
		for (int j = 0; j < t.N; j++) {
			if (t.z[i][j] == 'K' || t.z[i][j] == 'P') {
				gMin = min(gMin, dp[i][j][1]);
				gMax = max(gMax, dp[i][j][2]);
			}
		}
	}

	/*
	printf(t.z);
	printf(t.h);
	printf(dp);
	*/
	return gMax - gMin;
}

int main() {
	ifstream in("tests.in");
	int T;
	in >> T;
	ofstream out("tests.out");
	for (int t = 0; t < T; t++) {
		Test test;
		in >> test.N;
		for (int i = 0; i < test.N; i++) {
			vector<char> zCur;
			for (int j = 0; j < test.N; j++) {
				char ch;
				in >> ch;
				zCur.push_back(ch);
				if (ch == 'P') {
					test.P = {i, j};
				}
			}

			test.z.push_back(zCur);
		}

		for (int i = 0; i < test.N; i++) {
			vector<long> hCur;
			for (int j = 0; j < test.N; j++) {
				long v;
				in >> v;
				hCur.push_back(v);
			}

			test.h.push_back(hCur);
		}

//		if (t == 1) 
		{
			out << solve(test) << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}

