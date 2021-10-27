#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int minim = -1;
int maxim;

void findPaths(int n, vector<vector<int>> nums, int path, int levelI, int levelJ) {
	if (levelI == n) {
		if (minim == -1 || path < minim) {
			minim = path;
		}
		else if (path > maxim) {
			maxim = path;
		}
	}
	for (int i = levelI; i < n; i++) {
		for (int j = levelJ; j <= levelJ + 1; j++) {
			cout << "i = " << i << " j = " << j << " nums[i][j] = " << nums[i][j];
			cout << " levelI = " << levelI << " levelJ = " << levelJ << " path = " << path << endl;
			findPaths(n, nums, path + nums[i][j], i + 1, j);
		}
		cout << endl;
		break;
	}
}

int main() {
	ifstream in("in8.txt");
	int n;
	in >> n;
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		int num; in >> num;
		return num;
	}
	vector<vector<int>> nums;
	for (int i = 0; i < n; i++) {
		vector<int> level;
		for (int j = 0; j < i + 1; j++) {
			int num;
			in >> num;
			level.push_back(num);
		}
		nums.push_back(level);
	}
	
	findPaths(n, nums, nums[0][0], 1, 0);
	cout << "min = " << minim << endl;
	cout << "max = " << maxim << endl;
	
	ofstream out("res.txt");
	out << minim << " " << maxim;
	in.close();
	out.close();
	
	cout << "Program is done.\n";
}