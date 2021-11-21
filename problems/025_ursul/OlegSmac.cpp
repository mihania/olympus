#include<vector>
#include<queue>
#include<iostream>
#include<fstream>

using namespace std;

int computation(int N, int S, vector<vector<char>>& grid, vector<vector<int>> timeOfBees, queue<vector<int>>& hive) {
	while (!hive.empty()) {
		vector<int> p = hive.front();
		int row = p[0];
		int col = p[1];
		int minute = p[2];
		hive.pop();
		vector<vector<int>> bound = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (vector<int> v : bound) {
			if (row + v[0] >= 0
				&& col + v[1] >= 0
				&& row + v[0] < N
				&& col + v[1] < N
				&& grid[row + v[0]][col + v[1]] != 'T'
				&& timeOfBees[row + v[0]][col + v[1]] == -1) {
					timeOfBees[row + v[0]][col + v[1]] = minute + 1;
					p[0] = row + v[0];
					p[1] = col + v[1];
					p[2] = minute + 1;
					hive.push(p);
				}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << timeOfBees[i][j] << " ";
		}
		cout << endl;
	}
	
	return -1;
}

int main() {
	ifstream in("in1.txt");
	int kol;
	in >> kol;
	cout << "kol = " << kol << endl;
	for (int k = 0; k < kol; k++) {
		int N, S;
		in >> N >> S; //grid size and steps Mekko 
		//cout << "k = " << k << " N = " << N << " S = " << S << endl;
		vector<vector<char>> grid;
		vector<vector<int>> timeOfBees;
		queue<vector<int>> hive; //cells with bees 
		for (int i = 0; i < N; i++) { //data input
			vector<char> line;
			vector<int> lineTime;
			for (int j = 0; j < N; j++) {
				char c;
				in >> c;
				line.push_back(c);
				if (c == 'H') {
					vector<int> p = {i, j, 0};
					hive.push(p); //(row, col)
					lineTime.push_back(0);
				}
				else {
					lineTime.push_back(-1);
				}
			}
			timeOfBees.push_back(lineTime);
			grid.push_back(line);	
		}
		computation(N, S, grid, timeOfBees, hive);
		cout << endl;
	}
	
	ofstream out("res.txt");
	in.close();
	out.close();
}