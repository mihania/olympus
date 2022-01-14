#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>
#include<stdio.h>

using namespace std;

void nearestApple(vector<vector<int>>& grid, int y, int *xLow, int *xHigh) {
	if (y < grid[0].size()) {
		for (int i = 0; i < grid.size(); i++) {
			if (grid[i][y] == 1) {
				if (*xLow == -1) {
					*xLow = i;
				}
				*xHigh = i;
			} 
		}
	}
}

int solution(vector<pair<int, int>>& apples) {
	//apples[i].first = x, apples[i].second = y
	int maxX = apples[0].first; 
	int maxY = apples[0].second;
	for (int i = 1; i < apples.size(); i++) {
		if (apples[i].first > maxX) {
			maxX = apples[i].first; 
		}
		if (apples[i].second > maxY) {
			maxY = apples[i].second;
		}
	}
	
	vector<vector<int>> grid (maxX + 1, vector<int>(maxY + 1, 0));
	for (int i = 0; i < apples.size(); i++) { //marking apples in the grid
		grid[apples[i].first][apples[i].second] = 1;
	}
	
	//dp[i][j] - минимальное количество шагов змея должна пройти чтобы закончить сбор яблок на i-строке и j-м яблоке
	vector<vector<int>> dp(maxX + 1, vector<int>(maxY + 1, 0));
	int lastXLow = 0;
	int lastXHigh = 0;
	for (int i = 0; i <= maxX; i++) {
		if (grid[i][0] == 1) {
			dp[i][0] = i;
			if (lastXLow == 0) {
				lastXLow = i;
			}
			lastXHigh = i;
		}
	}
	
	int lastY = 0;
	for (int j = 0; j < grid[0].size(); j++) {
		int xLow = -1;
		int xHigh = -1;
		nearestApple(grid, j, &xLow, &xHigh);
		if (xLow != -1) {
			int way = min(abs(xHigh - lastXLow) + dp[lastXLow][lastY], abs(xHigh - lastXHigh) + dp[lastXHigh][lastY]) + (j - lastY);
			dp[xLow][j] = way + xHigh - xLow; //low apple
			if (xHigh != xLow && dp[xHigh][j] == 0) {
				way = min(abs(xLow - lastXLow) + dp[lastXLow][lastY], abs(xLow - lastXHigh) + dp[lastXHigh][lastY]) + (j - lastY);
				dp[xHigh][j] = way + xHigh - xLow; //high apple
			}
			lastY = j;
			lastXLow = xLow;
			lastXHigh = xHigh;
		}
	}
	
	return min(dp[lastXLow][lastY], dp[lastXHigh][lastY]);
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int n;
		in >> n;
		vector<pair<int, int>> apples;
		for (int j = 0; j < n; j++) {
			int x; int y;
			in >> x >> y;
			apples.push_back(pair<int, int> {x - 1, y - 1});
		}
		out << solution(apples) << endl;
	}
	
	in.close();
	out.close();
}