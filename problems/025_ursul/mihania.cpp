#include<fstream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

// 4-way directions: north, east, south, west.
int dpp[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; 

void print(vector<vector<int>>& v) {
	for (vector<int>& vv : v) {
		for (int k : vv) {
			printf("%d ", k);
		}

		printf("\n");
	}

	printf("\n");

}


void print(vector<string>& v) {
	for (string& s : v) {	
		printf("%s\n", s.c_str());
	}

	printf("\n");

}

// return T[i][j], where T[i][j] is the minimum time the bee can enter the cell i, j 
vector<vector<int>> getMinBeeTime(vector<string>& m) {
	vector<vector<int>> res(m.size(), vector<int>(m.size(), m.size() * m.size()));
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

	return res;
}



int getMaxBearStartTime(vector<string>& m, vector<vector<int>>& beeTime, int S, pair<int, int>& bearPos, pair<int, int>& housePos) {
	// queue of i, j, remaining steps left before entering the cell.
	queue<tuple<int, int, int>> q;

	// bearTime[i][j] = max bear time to leave cell {i, j}	
	vector<vector<int>> bearTime(m.size(), vector<int>(m.size(), -1));

	// as bear won't leave the hose, bear time does not matter in house cell,  setting to a high number.
	int maxTime = m.size() * m.size();
	bearTime[housePos.first][housePos.second] = maxTime;
	q.push({housePos.first, housePos.second, S - 1});
	
	while (!q.empty()) {
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		int remSteps = get<2>(q.front());
		//printf("i=%d j=%d remSteps=%d\n", i, j, remSteps);
		q.pop();

		for (auto& dp : dpp) {
			int ni = i + dp[0];
			int nj = j + dp[1];
			
			// checking boundaries
			if (ni >= 0 && ni < m.size() && nj >= 0 && nj < m[0].size() 
					
					// can bear run to ni nj?
					&& (m[ni][nj] == 'G' ||  m[ni][nj] == 'M')) {


				int pureTime  = bearTime[i][j] - (remSteps == 0 ? 1 : 0);
				int safeTime  = min(beeTime[ni][nj], pureTime);
				// printf("[%d,%d]->[%d,%d] pureTime=%d safeTime=%d remSteps=%d\n", i, j, ni, nj, pureTime, safeTime, remSteps);
				// is bear time valid
				if (safeTime >= 0 
						// is bear time better?
						&& bearTime[ni][nj] <  safeTime) {
					bearTime[ni][nj] = safeTime;
					q.push({ni, nj, beeTime[ni][nj] < pureTime ? S - 1 : (remSteps == 0 ? S - 1 : remSteps - 1)});
				}

			//	print(bearTime);
			}	
		}
	}

	// checking for case when bear is absolutely safe to start at any time
	// print(bearTime);
	return bearTime[bearPos.first][bearPos.second] == maxTime ? -1 : max(0, bearTime[bearPos.first][bearPos.second] - 1);
}

class Test {
public:
	int N;
	int S;
	vector<string> m;
	int res;
};

int solve(Test& test) {
	pair<int, int> bearPos;
	pair<int, int> housePos;
	// printf("%d %d\n", test.N, test.S);
	// print(test.m);
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
	// print(beeTime);
	return getMaxBearStartTime(test.m, beeTime, test.S, bearPos, housePos);
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
		// if (i == 2) 
		{
			out << solve(tests[i]) << endl;
		}
	}

	out.close();
	return 0;
}
