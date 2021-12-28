#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

vector<int> add(vector<int> v, vector<int> num) { //v.size >= num.size
	for (int i = v.size() - 1, j = num.size() - 1; i > 0 && j >= 0; i--) {
		int s = v[i] + num[j];
		if (s > 9) {
			v[i] = s % 10;
			v[i - 1] += 1;
		}
		else {
			v[i] = s;
		}
		j--;
	}
	
	return v;
}

vector<int> solution(int S, int N) {
	vector<vector<vector<int>>> dp (N, vector<vector<int>> (N * S, vector<int>(56, 0)));
	vector<int> one;
	one.push_back(1);
	for (int j = 0; j < S; j++) {
		dp[0][j] = add(dp[0][j], one);
	}
	for (int i = 1; i < N; i++) {
		for (int j = i; j < (i + 1) * S; j++) {
			dp[i][j] = add(dp[i - 1][j - 1], dp[i][j - 1]);
		}
	}
	vector<int> res (56, 0);
	for (int j = 0; j < N * S; j++) {
		res = add(res, dp[N - 1][j]);
	}
	return res;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	int S, N;
	for (int i = 0; i < T; i++) {
		in >> S;
		in >> N;
		vector<int> v = solution(S, N);
		
		bool isNum = false;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] != 0) {
				isNum = true;
			}
			if (isNum) {
				out << v[j];
			}
		}
		out << endl;
	}
	
	in.close();
	out.close();
}