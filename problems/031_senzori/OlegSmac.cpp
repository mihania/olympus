#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

bool sensorIsInRadius(int xi, int yi, int xj, int yj, int radius) {
	double d = sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
	if (d <= radius) {
		return true;
	}
	return false;
}

int solution(int K, int N, int M, vector<pair<int, int>>& sensors, vector<vector<int>>& points, vector<int>& badPoints) {
	vector<vector<int>> senPoints; //all points of this sensor
	for (int i = 0; i < sensors.size(); i++) {
		vector<int> senIPoints; //points of sensor i
		for (int j = 0; j < points.size(); j++) {
			if (points[j].size() != 0) {
				if (sensorIsInRadius(sensors[i].first, sensors[i].second, points[j][0], points[j][1], points[j][2])) {
					senIPoints.push_back(j);
				}
			}
		}
		senPoints.push_back(senIPoints);
	}
	
	int res = 0;
	for (int i = 0; i < senPoints.size(); i++) {
		if (senPoints[i].size() == 0) {
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
		vector<int> badPoints;
		for (int j = 0; j < M; j++) {
			int num;
			in >> num;
			vector<int> empty;
			points[num - 1] = empty;
			badPoints.push_back(num - 1);
		}
		
		out << solution(K, N, M, sensors, points, badPoints) << endl;
	}
	
	in.close();
	out.close();
}