#include<fstream>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

long distLeft(long p, long L, long R) {
	if (p < L) {
		// p L R
		return R - p + R - L;
	} else if (p < R) {
		// L p R
		return R - L + R - p;
	} else {
		// L R p
		return p - L;
	}
}

long distRight(long p, long L, long R) {
	if (p < L) {
		// p L R
		return R - p;
	} else if (p < R) {
		// L p R
		return R - L + p - L;
	} else {
		// L R p
		return p - L + R - L;
	}
}

long solve(vector<vector<long>> v) {

	// m[y] = {x1, x2}, x1 - left most x in row y, x2 - right most x in row y. 
	map<long, pair<long, long>> m;
	m[1] = {1, 1};
	for (const auto& c : v) {
		printf("%ld %ld\n", c[0], c[1]);
		if (m.find(c[1]) == m.end()) {
			m[c[1]] = {c[0], c[0]};
		} else {
			m[c[1]].first = min(m[c[1]].first, c[0]);
			m[c[1]].second = max(m[c[1]].second, c[0]);
		}
	}

	for (auto kv : m) {
		printf("%ld [%ld %ld]\n", kv.first, kv.second.first, kv.second.second);
	}

	// dp[y] = {x1, minSteps if snake eats on row y last  (x1, y), x2, minSteps if snakes east last on row y  (x2, y)}
	map<long, vector<long>> dp;
	dp[1] = {1, 2 * (m[1].second - m[1].first), 1, m[1].second - m[1].first};
	long prevRow = -1;
	for (auto kv : m) {
		long row = kv.first;
		long left = kv.second.first;
		long right = kv.second.second;
		if (row != 1) {
			// vertical distance between cur row and prev row.
			auto h = row - prevRow;
			dp[row] = {
				left, 
				h + min(
						distLeft(dp[prevRow][0], left, right) + dp[prevRow][1], 
						distLeft(dp[prevRow][2], left, right) + dp[prevRow][3]), 
				right,
				h + min(
						distRight(dp[prevRow][0], left, right) + dp[prevRow][1],
						distRight(dp[prevRow][2], left, right) + dp[prevRow][3])	
			};
		}

		printf("row=%ld {%ld %ld %ld %ld}\n", row, dp[row][0], dp[row][1], dp[row][2], dp[row][3]);
		prevRow = row;
	}
	
	return min(dp[prevRow][1], dp[prevRow][3]);
}


int main() {
    ifstream in("tests.in");
    int T;
    in >> T;
    ofstream out("tests.out");
    for (int t = 0; t < T; t++) {
    	int n;
	in >> n;
	vector<vector<long>> v;
	for (int i = 0; i < n; i++) {
		long x;
		long y;
		in >> x >> y;
		v.push_back({x, y});
	}

	if (t == 9) 
	{
		out << solve(v) << endl;
	}
    }


    in.close();
    out.close();
    return 0;
}
