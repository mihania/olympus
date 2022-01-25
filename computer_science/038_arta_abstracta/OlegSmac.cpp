#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int solution(vector<vector<int>>& points) {
	//sorting points by x
	for (int i = 0; i < points.size(); i++) { 
		for (int j = i + 1; j < points.size(); j++) {
			if (points[i][0] > points[j][0]) {
				vector<int> tmp = points[i];
				points[i] = points[j];
				points[j] = tmp;
			}
		}
	}
	
	//by this moment there are 4 points in test
	int res = 0;
	for (int i = 0; i < points.size(); i++) { 
		for (int j = i + 1; j < points.size(); j++) {
			for (int p = j + 1; p < points.size(); p++) {
				for (int q = p + 1; q < points.size(); q++) {
					if (points[i][2] == points[j][2] && points[j][2] == points[p][2] && points[p][2] == points[q][2] && 
						abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]) == abs(points[i][1] - points[p][1]) + abs(points[i][0] - points[p][0]) && 
						abs(points[j][0] - points[p][0]) + abs(points[j][1] - points[p][1]) == abs(points[i][0] - points[q][0]) + abs(points[i][1] - points[q][1]) &&
						abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]) == abs(points[j][0] - points[q][0]) + abs(points[j][1] - points[q][1]) &&
						abs(points[i][0] - points[p][0]) + abs(points[i][1] - points[p][1]) == abs(points[p][1] - points[q][1]) + abs(points[p][0] - points[q][0])) {
						res++;
						//cout << points[i][2] << " " << points[j][2] << " " << points[p][2] << " " << points[q][2] << endl;
						cout << points[i][0] << " " << points[i][1] << endl;
						cout << points[j][0] << " " << points[j][1] << endl;
						cout << points[p][0] << " " << points[p][1] << endl;
						cout << points[q][0] << " " << points[q][1] << endl;
						cout << endl;
					}	
				}
			}
		}
	}
	
	cout << "res = " << res << endl;
	return res;
}

int main() {
	ifstream in("in2.txt");
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
				v.push_back(num);
			}
			points.push_back(v);
		}
		out << solution(points) << endl;
	}
	
	in.close();
	out.close();
}