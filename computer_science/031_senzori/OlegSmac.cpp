#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>
#include<unordered_set>

using namespace std;

bool sensorIsInRadius(int xi, int yi, int xj, int yj, int radius) {
	double d = sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
	if (d <= radius) {
		return true;
	}
	return false;
}

int solution(int K, int N, int M, vector<pair<int, int>>& sensors, vector<vector<int>>& points, unordered_set<int>& badPoints) {
	int res = 0;
	for (int i = 0; i < sensors.size(); i++) {
		bool senIPoints = false; //points of sensor i (true - are points, false - no points)
		for (int j = 0; j < points.size(); j++) {
			if (sensorIsInRadius(sensors[i].first, sensors[i].second, points[j][0], points[j][1], points[j][2]) &&
				badPoints.find(j) == badPoints.end()) {
					senIPoints = true;
					break;
			}
		}
		if (!senIPoints) { //this sensor should be replaced
			res++;
		}
	}
	
	return res;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	int K, N, M; 
	for (int i = 0; i < T; i++) {
		in >> K;
		vector<pair<int, int>> sensors;
		for (int j = 0; j < K; j++) {
			pair<int, int> sensor; //sensor[0] = x[i], sensor[1] = y[i]
			int num;
			in >> num;
			sensor.first = num;
			in >> num;
			sensor.second = num;
			sensors.push_back(sensor);
		}
		in >> N;
		vector<vector<int>> points;
		for (int j = 0; j < N; j++) {
			vector<int> point; //point[0] = x[j], point[1] = y[j], point[2] = r[j]
			for (int p = 0; p < 3; p++) {
				int num;
				in >> num;
				point.push_back(num);
			}
			points.push_back(point);
		}
		in >> M;
		unordered_set<int> badPoints;
		for (int j = 0; j < M; j++) {
			int num;
			in >> num;
			badPoints.insert(num - 1);
		}
		
		out << solution(K, N, M, sensors, points, badPoints) << endl;
	}
	
	in.close();
	out.close();
}