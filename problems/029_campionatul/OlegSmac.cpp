#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<fstream>

using namespace std;

vector<long long> sumsOfSubsets (vector<long long>& c, long long S, int from, int to) {
	vector<long long> res; //res - sums of part of matches
	for (int x = 0; x < pow(2, to - from); x++) {
		long long sum = 0;
		int k = x;
		int i = 0;
		while (k > 0) {
			if (k % 2 == 1) {
				sum += c[from + i];
			}
			k /= 2;
			i++;
		}
		if (sum <= S && sum != 0) {
			res.push_back(sum);
		}
	}
	return res;
}

long long solution(vector<long long>& c, int n, long long S) {
	int mid = c.size() / 2;
	vector<long long> sum1 = sumsOfSubsets(c, S, 0, mid); //sum1 - sums of first part of matches
	vector<long long> sum2 = sumsOfSubsets(c, S, mid, c.size()); //sum2 - sums of second part of matches
	
	long long res = 1;
	res += sum1.size() + sum2.size();
	sort(sum2.begin(), sum2.end());
	
	for (int i = 0; i < sum1.size(); i++) {
		long long num = S - sum1[i];
		int low = 0;
		int high = sum2.size() - 1; 
		while (low <= high) {
			int middle = low + (high - low) / 2;
			if (num < sum2[middle]) {
				high = middle - 1;
			}
			else {
				low = middle + 1;
			}
		}
		res += low;
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