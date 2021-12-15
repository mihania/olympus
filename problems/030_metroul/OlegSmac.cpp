#include<vector>
#include<sstream>
#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

vector<int> findNearStations(int station, vector<vector<int>>& ways, vector<int>& timeForStations) {
	vector<int> res;
	for (int i = 0; i < ways.size(); i++) {
		for (int j = 0; j < ways[i].size(); j++) {
			if (ways[i][j] == station) {
				for (int k = 0; k < ways[i].size(); k++) {
					if (ways[i][k] != station && timeForStations[ways[i][k]] == -1) {
						res.push_back(ways[i][k]);
					}
				}
				break;
			}
		}
	}
	return res;
}

int solution(int m, int x, int y, vector<vector<int>>& ways) {
	queue<int> stations;
	stations.push(x);
	vector<int> timeForStations (m, -1);
	
	while (!stations.empty()) {
		int st = stations.front();
		stations.pop();
		vector<int> found = findNearStations(st, ways, timeForStations);
		for (int i = 0; i < found.size(); i++) {
			stations.push(found[i]);
			timeForStations[found[i]] = timeForStations[st] + 1;
		}
		
		if (timeForStations[y] != -1) {
			return timeForStations[y];
		}
		
	}
	return -1;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	int n, m, x, y;
	int num;
	for (int i = 0; i < T; i++) {
		in >> n >> m >> x >> y;
		vector<vector<int>> ways;
		string s;
		getline(in, s);
		for (int j = 0; j < n; j++) {
			vector<int> way;
			getline(in, s);
			istringstream nums;
			nums.str(s);
			int num;
			while (nums >> num) {
				way.push_back(num - 1);
			}
			ways.push_back(way);
		}
		out << solution(m, x - 1, y - 1, ways) << endl;
	}
	
	in.close();
	out.close();
}