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

bool canReach(Test& t, long houseCount, long minH, long maxH) {
	vector<vector<bool>> visited(t.N, vector<bool>(t.N, false));
	
	if (t.z[t.P.first][t.P.second] < minH || t.z[t.P.first][t.P.second] > maxH) {
		return false;
	}	

	queue<tuple<int, int>> q;
	q.push({t.P.first, t.P.second});
	visited[t.P.first][t.P.second] = true;
	int count = 0;
	while (!q.empty() && count < houseCount) {
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		q.pop();
		
		for (auto& dpp : dppp) {
			int ni = i + dpp[0];
			int nj = j + dpp[1];
			if (ni >= 0 && ni < t.N && nj >= 0 && nj < t.N
					&& !visited[ni][nj] 
					&& t.z[ni][nj] >= minH && t.z[ni][nj] <= maxH) {
				
				visited[ni][nj] = true;
				q.push({ni, nj});
				if (t.h[ni][nj] == 'K') {
					count++;
				}
			}	
		}
	}

	return count == houseCount;
}

bool canReach(Test& t, long houseCount, long interval, long minH, long maxH) {
	for (int i = minH; i + interval <= maxH; i++) {
		if (canReach(t, houseCount, i, i + interval)) {
			return true;
		}
	}

	return false;
}

long solveV2(Test& t) {
	// getting some statistics
	auto maxH = 0; 		// the max height of all cells
	auot minH = LONG_MAX;	// the min height of all cells
	long count = 0; 	// number of houses.
	for (auto i = 0; i < t.h.size(); i++) {
		for (auto j = 0; j < t.h.size(); j++) {
			if (t.z[i][j] == 'K') {
				count++;
			}
			
			minH = min(minH, t.h[i][j]);
			maxH = max(maxH, t.h[i][j]);
		}
	}


	// binary searh on min interval size that is enough to get to all houses.
	auto i = 0;
	auto j = maxH;
	while (i < j) {
		auto mid = i + (j - i) / 2;
		if (canReach(t, count, mid, minH, maxH)) {
			j = mid;
		} else {
			i = mid + 1;
		}
	}

	return j;
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
			out << solveV2(test) << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}

