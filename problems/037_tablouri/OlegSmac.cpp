#include<vector>
#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

vector<vector<int>> bound = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> solution(vector<vector<int>>& grid, int p, int q, int k) {
	queue<pair<int, int>> queue;
	pair<int, int> coord (p, q);
	queue.push(coord);
	while (!queue.empty()) {
		pair<int, int> coord = queue.front();
		queue.pop();
		int row = coord.first;
		int col = coord.second;
		for (vector<int>& v : bound) {
			if (row + v[0] >= 0 &&
				col + v[1] >= 0 &&
				row + v[0] < grid.size() &&
				col + v[1] < grid[0].size() &&
				grid[row + v[0]][col + v[1]] == grid[row][col]) {
					coord.first = row + v[0];
					coord.second = col + v[1];
					queue.push(pair<int, int> (row + v[0], col + v[1]));
				}
		}
		grid[row][col] = k;
	}
	return grid;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int n;
		int m;
		in >> n >> m;
		vector<vector<int>> grid (n, vector<int>(m, 0));
		int num;
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < m; t++) {
				in >> num;
				grid[j][t] = num; 
			}
		}
		int p;
		int q;
		int k;
		in >> p >> q >> k;
		grid = solution(grid, p - 1, q - 1, k);
		
		//output
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < m; t++) {
				out << grid[j][t] << " ";
			}
			out << endl;
		}
	}
	
	in.close();
	out.close();
}