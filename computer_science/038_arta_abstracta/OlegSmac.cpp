#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

double dist(int ix, int iy, int jx, int jy) {
	return sqrt(pow(ix - jx, 2) + pow(iy - jy, 2));
}

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
	//sorting by y
	for (int i = 0; i < points.size(); i++) { 
		for (int j = i + 1; j < points.size(); j++) {
			if (points[i][0] == points[j][0] && points[i][1] > points[j][1]) {
				vector<int> tmp = points[i];
				points[i] = points[j];
				points[j] = tmp;
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < points.size(); i++) { 
		for (int j = i + 1; j < points.size(); j++) {
			for (int p = j + 1; p < points.size(); p++) {
				for (int q = p + 1; q < points.size(); q++) {
					if (points[i][2] == points[j][2] && points[j][2] == points[p][2] && points[p][2] == points[q][2] && 
					dist(points[i][0], points[i][1], points[j][0], points[j][1]) == dist(points[p][0], points[p][1], points[q][0], points[q][1]) &&
					dist(points[i][0], points[i][1], points[p][0], points[p][1]) == dist(points[j][0], points[j][1], points[q][0], points[q][1]) &&
					dist(points[i][0], points[i][1], points[q][0], points[q][1]) == dist(points[j][0], points[j][1], points[p][0], points[p][1]) &&
					dist(points[i][0], points[i][1], points[j][0], points[j][1]) == dist(points[j][0], points[j][1], points[q][0], points[q][1])) {
						res++;
					}	
				}
			}
		}
	}
	
	cout << "res = " << res << endl;
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
				v.push_back(num);
			}
			points.push_back(v);
		}
		out << solution(points) << endl;
	}
	
	in.close();
	out.close();
}
