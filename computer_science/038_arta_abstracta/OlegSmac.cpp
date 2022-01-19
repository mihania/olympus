#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int solution(vector<vector<int>>& points) {
	int xMax = 0;
	int yMax = 0;
	for (int i = 0; i < points.size(); i++) {
		if (points[i][0] > xMax) {
			xMax = points[i][0];
		}
		if (points[i][1] > yMax) {
			yMax = points[i][1];
		}
	}
	vector<vector<int>> grid (xMax + 1, vector<int>(yMax + 1, -1));
	for (int i = 0; i < points.size(); i++) {
		grid[points[i][0]][points[i][1]] = points[i][2];
	}
	int res = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] != -1) {
				for (int k = 1; k < min(xMax - i + 1, yMax - j + 1); k++) {
					if (grid[i][j] == grid[i][j + k] && grid[i][j] == grid[i + k][j] && grid[i][j] == grid[i + k][j + k]) {
						res++;
					}
					if (j != 0 && i + 2 * k < grid.size() && j - k >= 0 && j + k < grid[i].size()
						&& grid[i][j] == grid[i + 2*k][j] && grid[i][j] == grid[i + k][j - k] && grid[i][j] == grid[i + k][j + k]) {
						res++;
					}
				}
			}
		}
	}
	
	return res;
}

int main() {
	ifstream in("TESTS.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int n;
		in >> n;
		vector<vector<int>> points;
		for (int j = 0; j < n; j++) {
			vector<int> v;
			int num;
			for (int p = 0; p < 3; p++) {
				in >> num;
				v.push_back(num - 1);
			}
			points.push_back(v);
		}
		out << solution(points) << endl;
	}
	
	in.close();
	out.close();
}