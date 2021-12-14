#include<fstream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
#include<iostream>

using namespace std;

int dpp[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 

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
	
	// maxMin[i][j] - max minimal height to reach point (i, j) from postal office.
	vector<vector<long>> maxMin(t.N, vector<long>(t.N, -1));

	// minMax[i][j] - min maximal height to reach point (i, j) from postal office. 
	vector<vector<long>> minMax(t.N, vector<long>(t.N, -1));

	queue<tuple<int, int, long, long>> q;
	q.push({t.P.first, t.P.second, t.h[t.P.first][t.P.second], t.h[t.P.first][t.P.second]});
	while (!q.empty()) {
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		long prevMaxMin = get<2>(q.front());
		long prevMinMax = get<3>(q.front());
		q.pop();
		for (auto& dp : dpp) {
			int ni = i + dp[0];
			int nj = j + dp[1];
			if (ni >= 0 && ni < t.N && nj >= 0 && nj < t.N) {
			
				bool updated = false;	
				if (maxMin[ni][nj] == -1 || maxMin[ni][nj] < min(t.h[ni][nj], prevMaxMin)) {
					maxMin[ni][nj] = min(t.h[ni][nj], prevMaxMin);
					updated = true;
				}

				if (minMax[ni][nj] == -1 || minMax[ni][nj] > max(t.h[ni][nj], prevMinMax)) {
					minMax[ni][nj] = max(t.h[ni][nj], prevMinMax);
					updated = true; 
				}

				if (updated) {
					q.push({ni, nj, maxMin[ni][nj], minMax[ni][nj]});
				}
			}
		}
	}

	long globalMin = LONG_MAX;
	long globalMax = -1;
	long res = 0;
	for (int i = 0; i < t.N; i++) {
		for (int j = 0; j < t.N; j++) {
			if (t.z[i][j] == 'K' || t.z[i][j] == 'P') {
				globalMin = min(globalMin, maxMin[i][j]);
				globalMax = max(globalMax, minMax[i][j]);
			}
		}
	}

	printf(t.z);
	printf(t.h);
	printf(maxMin);
	printf(minMax);
	return globalMax - globalMin;

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

		if (t == 6) 
		{
			out << solve(test) << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}

