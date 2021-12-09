#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<fstream>

using namespace std;

int solution(vector<long long>& c, int n, long long S) {
	vector<long long> variants(n, 0); //variants[i] - num of all variants
	vector<vector<long long>> sums; //sums[i] - sum every variant in which is match i
	sort(c.begin(), c.end());
	long long res = 1;
	for (int i = 0; i < n; i++) {
		vector<long long> sum;
		if (c[i] <= S) {
			variants[i] = 1;
			sum.push_back(c[i]);
			for (int j = i - 1; j >= 0; j--) {
				for (int k = 0; k < sums[j].size(); k++) {
					long long num = c[i] + sums[j][k];
					if (num <= S) {
						sum.push_back(num);
						variants[i]++;
					}
				}
			}
		}
		sums.push_back(sum);
		res += variants[i];
	}
	
	return res;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T, n;
	long long S;
	in >> T;
	for (int i = 0; i < T; i++) {
		in >> n >> S;
		cout << "S = " << S << endl;
		vector<long long> c;
		for (int j = 0; j < n; j++) {
			long long num;
			in >> num;
			c.push_back(num);
		}
		out << solution(c, n, S) << endl;
	}
	
	in.close();
	out.close();
}