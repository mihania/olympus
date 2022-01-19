#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

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
	vector<vector<int>> grid (xMax - 1, vector<int>(yMax - 1, -1));
	for (int i = 0; i < points.size(); i++) {
		grid[points[i][0]][points[i][1]] = points[i][2];
	}
	
	
	return -1;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < 1; i++) {
		int n;
		in >> n;
		vector<vector<int>> points;
		for (int j = 0; j < n; j++) {
			vector<int> v;
			int num;
			for (int p = 0; p < 3; p++) {
				in >> num;
				v.push_back(num);
			}
			points.push_back(v);
		}
		out << solution(points) << endl;
	}
	
	in.close();
	out.close();
}