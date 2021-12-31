#include<vector>
#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

vector<vector<int>> bound = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

bool canIGetFromPToAllK(vector<vector<char>>& z, vector<vector<int>>& h, pair<int, int>& p, int k, int minH, int maxH) {
	vector<vector<int>> visit (z.size(), vector<int>(z.size(), false)); //visiting all cells
	visit[p.first][p.second] = true;
	int visitKCell = 0; //visiting K cells
	queue<pair<int, int>> q;
	if (h[p.first][p.second] >= minH &&
		h[p.first][p.second] <= maxH) {
			q.push(p);
	}
	while (!q.empty()) {
		pair<int, int> cell = q.front();
		int row = cell.first;
		int col = cell.second;
		q.pop();
		for (vector<int> v : bound) {
			if (row + v[0] >= 0 &&
				row + v[0] < z.size() &&
				col + v[1] >= 0 &&
				col + v[1] < z.size() &&
				visit[row + v[0]][col + v[1]] == false &&
				h[row + v[0]][col + v[1]] >= minH &&
				h[row + v[0]][col + v[1]] <= maxH) {
					q.push(pair<int, int> {row + v[0], col + v[1]});
					visit[row + v[0]][col + v[1]] = true;
					if (z[row + v[0]][col + v[1]] == 'K') {
						visitKCell++;
					}
				}
		}
	}
	//cout << "visK = " << visitKCell << " k = " << k << endl; 
	return visitKCell == k;
}

int solution(vector<vector<char>>& z, vector<vector<int>>& h, pair<int, int>& p, vector<pair<int, int>>& k) {
	//finding heights between P and all K cells
	int max = h[p.first][p.second];
	int high = 1000000;
	int low = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (canIGetFromPToAllK(z, h, p, k.size(), 0, mid)) {
			high = mid - 1;
			max = mid;
		}
		else {
			low = mid + 1;
		}
	}
	cout << "maxH = " << max;
	
	int min = h[p.first][p.second];
	high = h[p.first][p.second];
	low = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (canIGetFromPToAllK(z, h, p, k.size(), mid, 1000000)) {
			low = mid + 1;
			min = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << " minH = " << min << endl;
	
	//finding heights between k cells
	
	
	cout << "res = " << max - min << endl;
	cout << "my test = " << canIGetFromPToAllK(z, h, p, k.size(), 1, 1000000) << endl;
	return max - min;
}

int main() {
	ifstream in("in5.txt");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int n;
		in >> n;
		vector<vector<char>> z;
		pair<int, int> p;
		vector<pair<int, int>> kCells;
		for (int j = 0; j < n; j++) {
			vector<char> v;
			for (int k = 0; k < n; k++) {
				char c;
				in >> c;
				v.push_back(c);
				if (c == 'P') {
					p.first = j;
					p.second = k;
				}
				if (c == 'K') {
					kCells.push_back(pair<int, int> {j, k});
				}
			}
			z.push_back(v);
		}
		vector<vector<int>> h;
		for (int j = 0; j < n; j++) {
			vector<int> v;
			for (int k = 0; k < n; k++) {
				int num;
				in >> num;
				v.push_back(num);
			}
			h.push_back(v);
		}
		out << solution(z, h, p, kCells) << endl;
	}
	
	in.close();
	out.close();
}