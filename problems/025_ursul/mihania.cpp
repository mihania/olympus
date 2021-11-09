#include<fstream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

// 4-way directions: north, east, south, west.
int dpp[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; 


void printf(vector<vector<int>> m) {
	for (auto& v : m) {
		for (auto k : v) {
			printf("%d ", k);
		}

		printf("\n");
	}

	printf("\n");
}

// return T[i][j], where T[i][j] is the minimum time the bee can reach the cell i, j 
vector<vector<int>> getMinBeeTime(vector<string>& m) {
	vector<vector<int>> res(m.size(), vector<int>(m.size(), INT_MAX));
  	queue<pair<int, int>> q;	
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			if (m[i][j] == 'H') {
				q.push({i, j});
				res[i][j] = 0;
			}
		}
	}

	// breath-first search
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (auto& dp : dpp) {
			int ni = i + dp[0];
			int nj = j + dp[1];

			if (
					// checking boundaries
					ni >= 0 && ni < m.size() && nj >= 0 && nj < m[0].size() 
						
					// can bee fly? we allow to fly into the house to check the bee time in the house,
					// but won't let the bee fly out of the house.
					&& m[ni][nj] != 'T'

					// can min bee time be decreased?
					&& res[ni][nj] > res[i][j] + 1) {
				res[ni][nj] = res[i][j] + 1;

				// bee cannot fly from bear's house.
				if (m[ni][nj] != 'D') {
					q.push({ni, nj});
				}
			}
		}
	}

	printf(res);

	return res;
}



int getMaxBearStartTime(vector<string>& m, vector<vector<int>>& beeTime, int S, pair<int, int>& bearPos, pair<int, int>& housePos) {
	// queue of i, j, remaining steps
	queue<tuple<int, int, int>> q;

	// bearTime[i][j] = max bear time to leave cell {i, j} before safely getting into house.	
	vector<vector<int>> bearTime(m.size(), vector<int>(m.size(), -1));

	bearTime[housePos.first][housePos.second] = beeTime[housePos.first][housePos.second];
	q.push({housePos.first, housePos.second, S});
	
	while (!q.empty()) {
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		int remSteps = get<2>(q.front());
		q.pop();

		for (auto& dp : dpp) {
			int ni = i + dp[0];
			int nj = j + dp[1];
			
			// checking boundaries
			if (ni >= 0 && ni < m.size() && nj >= 0 && nj < m[0].size() 
					
					// can bear run to ni nj?
					&& m[ni][nj] == 'G') {

				
				int time = bearTime[i][j] - (remSteps == 0 ? 1 : 0);

				// is bear time increasing?
				if (bearTime[ni][nj] < time 
				
					// can bear get faster then the bee?
					&& time <= beeTime[ni][nj]) {
						bearTime[ni][nj] = time;
						q.push({ni, nj, (remSteps == 0 ? S : remSteps - 1)});
				}
			}	
		}
	}

	
	printf(bearTime);
	return bearTime[bearPos.first][bearPos.second];
}


int main() {

	// reading input
	ifstream in("in.txt");
	int N, S;
	in >> N >> S;
	vector<string> m(N);
	pair<int, int> bearPos;
	pair<int, int> housePos;
	for (int i = 0; i < N; i++) {
		in >> m[i];
		for (int j = 0; j < m[i].length(); j++) {
			if (m[i][j] == 'M') {
				bearPos = {i, j};
			} else if (m[i][j] == 'D') {
				housePos = {i, j};
			}
		}
	}

	in.close();

	// calculations
	vector<vector<int>> beeTime = getMinBeeTime(m);
	int res = getMaxBearStartTime(m, beeTime, S, bearPos, housePos);
	
	// writing output 
	ofstream out("out.txt");
	out << res << endl;
	out.close();
	return 0;
}

