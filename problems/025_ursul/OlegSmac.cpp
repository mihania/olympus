#include<vector>
#include<queue>
#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream in("in1.txt");
	int kol;
	in >> kol;
	cout << "kol = " << kol << endl;
	for (int k = 0; k < kol; k++) {
		int N, S;
		in >> N >> S; //grid size and steps Mekko 
		cout << "k = " << k << " N = " << N << " S = " << S << endl;
		vector<vector<char>> grid;
		queue<int> hive; //cells with bees 
		for (int i = 0; i < N; i++) { //data input
			vector<char> line;
			for (int j = 0; j < N; j++) {
				char c;
				in >> c;
				line.push_back(c);
				if (c == 'H') {
					hive.push(i);
					hive.push(j);
				}
			}
			grid.push_back(line);	
		}
		
		while (!hive.empty()) {
			int l = hive.front();
			hive.pop();
			int c = hive.front();
			hive.pop();
			//cout << "l = " << l << " c = " << c << endl;
			if (l - 1 >= 0 && grid[l - 1][c] != 'T' && grid[l - 1][c] != 'D' && grid[l - 1][c] != 'H') {
				if (grid[l - 1][c] == 'M') {
					cout << "Sucks!" << endl;
				}
				grid[l - 1][c] = 'H';
				hive.push(l - 1);
				hive.push(c);
			}
			if (l + 1 != N && grid[l + 1][c] != 'T' && grid[l + 1][c] != 'D' && grid[l + 1][c] != 'H') {
				if (grid[l + 1][c] == 'M') {
					cout << "Sucks!" << endl;
				}
				grid[l + 1][c] = 'H';
				hive.push(l + 1);
				hive.push(c);
			}
			if (c - 1 >= 0 && grid[l][c - 1] != 'T' && grid[l][c - 1] != 'D' && grid[l][c - 1] != 'H') {
				if (grid[l][c - 1] == 'M') {
					cout << "Sucks!" << endl;
				}
				grid[l][c - 1] = 'H';
				hive.push(l);
				hive.push(c - 1);
			}
			if (c + 1 != N && grid[l][c + 1] != 'T' && grid[l][c + 1] != 'D' && grid[l][c + 1] != 'H') {
				if (grid[l][c + 1] == 'M') {
					cout << "Sucks!" << endl;
				}
				grid[l][c + 1] = 'H';
				hive.push(l);
				hive.push(c + 1);
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	
	ofstream out("res.txt");
	in.close();
	out.close();
}