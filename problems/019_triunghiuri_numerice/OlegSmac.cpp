#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main() {
	ifstream in("in5.txt");
	ofstream out("res.txt");
	vector<vector<int>> nums;
	vector<vector<int>> maxim;
	vector<vector<int>> minim;
	int n;
	in >> n;
	for (int i = 0; i < n; i++) {
		vector<int> level;
		vector<int> empty(i + 1, 0);
		for (int j = 0; j < i + 1; j++) {
			int num;
			in >> num;
			level.push_back(num);
		}
		nums.push_back(level);
		maxim.push_back(empty);
		minim.push_back(empty);
	}
	for (int i = 0; i < n; i++) { //filling in the maximum and minimum paths
		for (int j = 0; j < i + 1; j++) {
			if (i == 0) {
				maxim[i][j] = nums[i][j];
				minim[i][j] = nums[i][j];
			}
			else if (j == i) {
				maxim[i][j] = nums[i][j] + maxim[i - 1][j - 1];
				minim[i][j] = nums[i][j] + minim[i - 1][j - 1];
			}
			else if (j == 0) {
				maxim[i][j] = nums[i][j] + maxim[i - 1][j];
				minim[i][j] = nums[i][j] + minim[i - 1][j];
			}
			else {
				maxim[i][j] = nums[i][j] + max(maxim[i - 1][j - 1], maxim[i - 1][j]);
				minim[i][j] = nums[i][j] + min(minim[i - 1][j - 1], minim[i - 1][j]);
			} 
		}
	}
	auto maxRes = max_element(maxim[n - 1].begin(), maxim[n - 1].end());
	auto minRes = min_element(minim[n - 1].begin(), minim[n - 1].end());
	cout << "min = " << *minRes << endl;
	cout << "max = " << *maxRes << endl;
	
	out << *minRes << " " << *maxRes;
	in.close();
	out.close();
	
	cout << "Program is done.\n";
}