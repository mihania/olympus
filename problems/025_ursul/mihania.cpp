#include<fstream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

// 4-way directions: north, east, south, west.
int dpp[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; 

class Test {
public:
	int N;
	int S;
	vector<string> m;
};

// return T[i][j], where T[i][j] is the minimum time the bee can enter the cell i, j 
vector<vector<int>> getMinBeeTime(vector<string>& m) {
	vector<vector<int>> res(m.size(), vector<int>(m.size(), -1));
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
						
					// can bee fly into?
					&& m[ni][nj] != 'T' && m[ni][nj] != 'D'

					// can min bee time be decreased?
					&& (res[ni][nj] == -1 || res[ni][nj] > res[i][j] + 1)) {
				res[ni][nj] = res[i][j] + 1;
				q.push({ni, nj});
			}
		}
	}

	return res;
}

bool canBearReachHome(Test& test, vector<vector<int>>& beeTime,  pair<int, int>& bearPos, pair<int, int>& housePos, int startTime) {
	queue<tuple<int, int, int, int>> q;
	q.push({bearPos.first, bearPos.second, startTime, test.S - 1});

	// bearTime[i][j] = min  bear time to reach cell {i, j}	
	vector<vector<int>> bearTime(test.m.size(), vector<int>(test.m.size(), test.m.size() * test.m.size()));
	bearTime[bearPos.first][bearPos.second] = startTime;

	// did bee bite bear at the starting position?
	if (startTime >= beeTime[bearPos.first][bearPos.second]) {
		return false;
	}

	while (!q.empty()) {
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		
		// source bear time
		int t = get<2>(q.front());

		// remaining steps
		int rs = get<3>(q.front());
		q.pop();
		
		// new bear time
		int nt = rs > 0 ? t : t + 1;
				
		// new remaining steps
		int nrs = rs > 0 ? rs - 1 : test.S - 1;

		for (auto& dp : dpp) {
			
			// new bear coordinates
			int ni = i + dp[0];
			int nj = j + dp[1];

			if (
					// checking boundaries
					ni >= 0 && ni < test.m.size() && nj >= 0 && nj < test.m[0].size() 
					
					// can bear run to a new cell?	
					&& (test.m[ni][nj] == 'G' || test.m[ni][nj] == 'D')
			
					// preventing infinity loop		
					&& bearTime[ni][nj] > nt
					
					// did bear get earlier than the bee?
					&& (nt < beeTime[ni][nj] || beeTime[ni][nj] == -1)) {
				

				// if bear reach the house, we are ending here.
				if (test.m[ni][nj] == 'D') {
					// print(bearTime);
					return true;
				}
					
					
				bearTime[ni][nj] = nt;
				q.push({ni, nj, nt, nrs});		
			}
		}

	}

	return false;
		
}

int getMaxBearStartTime(Test& test,  vector<vector<int>>& beeTime, pair<int, int>& bearPos, pair<int, int>& housePos) {
	
	// binary searching the right most startTime.
	int start = -1;
	const int cellCount = test.m.size() * test.m.size();
	int end = cellCount;
	while (start < end) {
		int mid = max(0, start + (end - start + 1) / 2);
		if (canBearReachHome(test, beeTime, bearPos, housePos, mid)) {
			start = mid;
		} else {
			end = mid - 1;
		}
	}

	return end == cellCount ?  -1 : end;
}


int solve(Test& test) {
	pair<int, int> bearPos;
	pair<int, int> housePos;
	for (int i = 0; i < test.m.size(); i++) {
		for (int j = 0; j < test.m[i].length(); j++) {
			if (test.m[i][j] == 'M') {
				bearPos = {i, j};
			} else if (test.m[i][j] == 'D') {
				housePos = {i, j};
			}
		}
	}

	// calculations
	vector<vector<int>> beeTime = getMinBeeTime(test.m);
	return getMaxBearStartTime(test, beeTime, bearPos, housePos);
}

int main() {

	// reading input
	ifstream in("tests.in");
	int T;
	in >> T;
	vector<Test> tests;
	for (int t = 0; t < T; t++) {
		Test test;
		in >> test.N >> test.S;
		for (int i = 0; i < test.N; i++) {
			string s;
			in >> s;
			test.m.push_back(s);
		}

		tests.push_back(test);
	}

	in.close();
	
	// writing output 
	ofstream out("tests.out");
	for (int i = 0; i < tests.size(); i++) {
		out << solve(tests[i]) << endl;
	}

	out.close();
	return 0;
}
