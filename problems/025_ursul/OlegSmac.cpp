#include<vector>
#include<queue>
#include<iostream>
#include<fstream>

using namespace std;

int computation(int N, int S, vector<vector<char>>& grid, vector<vector<int>>& timeOfBees, 
				pair<int, int> Mekko, pair<int, int> D, queue<vector<int>>& hive) {
	vector<vector<int>> bound = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!hive.empty()) {
		vector<int> p = hive.front();
		int row = p[0];
		int col = p[1];
		int minute = p[2];
		hive.pop();
		for (vector<int> v : bound) {
			if (row + v[0] >= 0
				&& col + v[1] >= 0
				&& row + v[0] < N
				&& col + v[1] < N
				&& grid[row + v[0]][col + v[1]] != 'T'
				&& grid[row + v[0]][col + v[1]] != 'D'
				&& timeOfBees[row + v[0]][col + v[1]] == -1) {
					timeOfBees[row + v[0]][col + v[1]] = minute + 1;
					p[0] = row + v[0];
					p[1] = col + v[1];
					p[2] = minute + 1;
					hive.push(p);
				}
		}
	}
	
	vector<vector<int>> empty;
	for (int i = 0; i < N; i++) {
		vector<int> line;
		for (int j = 0; j < N; j++) {
			line.push_back(-1);
		}
		empty.push_back(line);
	}
	
	for (int i = 0; i < N * N; i++) {
		vector<vector<int>> timeOfMekko(empty);
		timeOfMekko[Mekko.first][Mekko.second] = i;
		queue<vector<int>> MekkoWay;
		vector<int> p = {Mekko.first, Mekko.second, 0}; //(row, col, steps)
		MekkoWay.push(p);
		while (!MekkoWay.empty()) {
			vector<int> p = MekkoWay.front();
			int row = p[0];
			int col = p[1];
			int steps = p[2] + 1;
			int minute = timeOfMekko[row][col];
			if (steps == S) {
				minute++;
				steps = 0;
			}
			MekkoWay.pop();
			for (vector<int> v : bound) {
				if (row + v[0] >= 0
					&& col + v[1] >= 0
					&& row + v[0] < N
					&& col + v[1] < N
					&& grid[row + v[0]][col + v[1]] != 'T'
					&& timeOfMekko[row + v[0]][col + v[1]] == -1
					&& (grid[row + v[0]][col + v[1]] == 'D' || timeOfBees[row + v[0]][col + v[1]] > minute)) {
						timeOfMekko[row + v[0]][col + v[1]] = minute;
						p[0] = row + v[0];
						p[1] = col + v[1];
						p[2] = steps;
						MekkoWay.push(p);
					}
			}
		}
		/*
		cout << "i = " << i << endl;
		for (int x = 0; x < timeOfMekko.size(); x++) {
			for (int y = 0; y < timeOfMekko[i].size(); y++) {
				cout << timeOfMekko[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		if (timeOfMekko[D.first][D.second] == -1) {
			return i - 1;
		}
		else if (i == N * N - 1) {
			return i;
		}
	}
	
	return -1;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int kol;
	in >> kol;
	for (int k = 0; k < kol; k++) {
		int N, S;
		in >> N >> S; //grid size and steps Mekko 
		vector<vector<char>> grid;
		vector<vector<int>> timeOfBees;
		queue<vector<int>> hive; //cells with bees
		pair<int, int> Mekko;
		pair<int, int> D;
		for (int i = 0; i < N; i++) { //data input
			vector<char> line;
			vector<int> lineBees;
			for (int j = 0; j < N; j++) {
				char c;
				in >> c;
				line.push_back(c);
				if (c == 'M') {
					Mekko.first = i;
					Mekko.second = j;
				}
				if (c == 'D') {
					D.first = i;
					D.second = j;
				}
				if (c == 'H') {
					vector<int> p = {i, j, 0}; //(row, col, minute)
					hive.push(p);
					lineBees.push_back(0);
				}
				else {
					lineBees.push_back(-1);
				}
			}
			timeOfBees.push_back(lineBees);
			grid.push_back(line);	
		}
		out << computation(N, S, grid, timeOfBees, Mekko, D, hive) << endl;
	}
	
	in.close();
	out.close();
}