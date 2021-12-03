#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

void filling(vector<vector<int>>& rectangles, int a, int b, int c, int d) {
	for (int i = 0; i < rectangles.size(); i++) { //H
		for (int j = 0; j < rectangles[i].size(); j++) { //W
			if (i >= b && i < d && j >= a && j < c) {
				rectangles[i][j] = 1;
			}
		}
	}
}

int solution(vector<vector<int>>& rectangles) {
	int res = 0;
	for (int i = 0; i < rectangles.size(); i++) { //H
		for (int j = 0; j < rectangles[i].size(); j++) { //W
			if (rectangles[i][j] == 0) {
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
		vector<vector<int>> rectangles(H, vector<int>(W, 0));
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