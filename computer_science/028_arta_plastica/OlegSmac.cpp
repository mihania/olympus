#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

void filling(vector<vector<bool>>& rectangles, int a, int b, int c, int d) {
	for (int i = 0; i < rectangles.size(); i++) { //H
		for (int j = 0; j < rectangles[i].size(); j++) { //W
			if (i >= b && i < d && j >= a && j < c) {
				rectangles[i][j] = true;
			}
		}
	}
}

int solution(vector<vector<bool>>& rectangles) {
	int res = 0;
	for (int i = 0; i < rectangles.size(); i++) { //H
		for (int j = 0; j < rectangles[i].size(); j++) { //W
			if (rectangles[i][j] == false) {
				res++;
			} 
		}
	}
	return res;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	int n, W, H;
	int a, b, c, d;
	for (int i = 0; i < T; i++) {
		in >> W >> H;
		vector<vector<bool>> rectangles(H, vector<bool>(W, false));
		in >> n;
		for (int j = 0; j < n; j++) {
			in >> a >> b >> c >> d;
			filling(rectangles, a, b, c, d);
		}
		out << solution(rectangles) << endl;
	}
	in.close();
	out.close();
}