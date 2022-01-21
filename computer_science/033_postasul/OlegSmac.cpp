#include<vector>
#include<iostream>
#include<fstream>
#include<queue>
#include<cmath>
#include<algorithm>

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
		for (vector<int>& v : bound) {
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
	return visitKCell == k;
}

long solution(vector<vector<char>>& z, vector<vector<int>>& h, pair<int, int>& p, vector<pair<int, int>>& k) {
	vector<long> heights; //all heights in the grid
    for (int i = 0; i < h.size(); i++) {
        for (int j = 0; j < h[i].size(); j++) {       
			heights.push_back(h[i][j]);
        }
    }
    sort(heights.begin(), heights.end());
	auto last = unique(heights.begin(), heights.end()); //removing dublicates (unique)
	heights.erase(last, heights.end());
    long res = heights[heights.size() - 1] - heights[0];
    for (int i = 0; i < heights.size(); i++) {
		int low = i;
		int high = heights.size();
		for (int j = 0; j < heights.size(); j++) { //(heights[i] + res) is the highest required element. Finding his position
			if (heights[j] >= heights[i] + res) {
				high = j;
				break;
			}
		}
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (canIGetFromPToAllK(z, h, p, k.size(), heights[i], heights[mid])) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		if (high >= heights.size()) {
			break;
		}
		else {
			res = min(res, heights[high] - heights[i]);
		}
    }
	
    return res;
}

int main() {
	ifstream in("tests.in");
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