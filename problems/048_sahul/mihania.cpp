#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

int solve(string& p1, string& p2) {
	vector<vector<int>> dpp = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
	int p1X = p1[0] - 'a';
	int p2X = p2[0] - 'a';
	int p1Y = stoi(p1.substr(1)) - 1;
	int p2Y = stoi(p2.substr(1)) - 1;
	vector<vector<bool>> visited(26, vector<bool>(26, false));
	queue<vector<int>> q;
	visited[p1X][p1Y] = true;
	q.push({p1X, p1Y});
	q.push({});
	int steps = 1;
	while (!q.empty()) {
		vector<int> cur = q.front();
		q.pop();
		if (cur.empty()) {
			steps++;
			if (!q.empty()) {
				q.push({});
			}	
		} else {
			for (auto& dp : dpp) {
				int nx = cur[0] + dp[0];
				int ny = cur[1] + dp[1];
				if (nx >= 0 && nx < visited.size() && ny >= 0 && ny < visited.size()
					&& !visited[nx][ny]
					) {
					
					if (nx == p2X && ny == p2Y) {
						// we reach the second knight, stop
						return steps % 2 == 0 ? steps / 2 : -1;
					}

					visited[nx][ny] = true;
					q.push({nx, ny});				
				}
			}
		}
	}
	
	return -1;
}

int main() {
   
   // reading the input file
   ifstream in("tests.in");
   ofstream out("tests.out");
   int T;
   in >> T;
   for (int i = 0; i < T; i++) {
      string p1, p2;
      in >> p1 >> p2;
      // if (i == 0)
      out << solve(p1, p2) << endl;
   } 
   
   in.close();
   out.close();
   return 0;
}
