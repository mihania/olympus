#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int minim = -1;
int maxim;
vector<vector<int>> nums;
int n;

void findPaths(int path, int levelI, int levelJ) {
	cout << "path = " << path << " levI = " << levelI << " levJ = " << levelJ << endl;
	if (levelI == n) {
		if (minim == -1 || path < minim) {
			minim = path;
		}
		else if (path > maxim) {
			maxim = path;
		}
	}
	else {
		findPaths(path + nums[levelI][levelJ], levelI + 1, levelJ);
		if (levelJ + 1 <= levelI) {
			findPaths(path + nums[levelI][levelJ + 1], levelI + 1, levelJ + 1);
		}
	}
}

int main() {
	ifstream in("in8.txt");
	ofstream out("res.txt");
	in >> n;
	if (n == 0) {
		out << 0 << " " << 0; 
	}
	for (int i = 0; i < n; i++) {
		vector<int> level;
		for (int j = 0; j < i + 1; j++) {
			int num;
			in >> num;
			level.push_back(num);
		}
		nums.push_back(level);
	}
	findPaths(0, 0, 0);
	cout << "min = " << minim << endl;
	cout << "max = " << maxim << endl;
	
	out << minim << " " << maxim;
	in.close();
	out.close();
	
	cout << "Program is done.\n";
}

/*
for (int j = levelJ; j <= levelJ + 1 && j <= levelI; j++) {
		//cout << "i = " << i << " j = " << j << " nums[i][j] = " << nums[i][j];
		cout << " levelI = " << levelI << " levelJ = " << levelJ << " path = " << path << endl;
		findPaths(path + nums[levelI][j], levelI + 1, j);
	}
*/