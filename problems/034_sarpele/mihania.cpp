#include<fstream>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

long distLeft(long p, long x1, long x2) {
	long res;
	if (p < x1) {
		// p x1 x2
		res = x2 - p + x2 - x1;
	} else if (p < x2) {
		// x1 p x2
		res = x2 - x1 + x2 - p;
	} else {
		// x1 x2 p
		res = p - x1;
	}

	if (res < 0) {
		printf("alarm!");
	}
	
	return res;
}

long distRight(long p, long x1, long x2) {
	long res;
	if (p < x1) {
		// p x1 x2
		res = x2 - p;
	} else if (p < x2) {
		// x1 p x2
		res = x2 - x1 + p - x1;
	} else {
		// x1 x2 p
		res = p - x1 + x2 - x1;
	}

	if (res < 0) {
		printf("alarm!");
	}

	
	return res;
}

long solve(vector<vector<long>> v) {
	
	// m[y] = {x1, x2}, x1 - left most x in row y, x2 - right most x in row y. 
	map<long, pair<long, long>> m;
	m[1] = {1, 1};
	for (const auto& c : v) {
		auto x = c[0];
		auto y = c[1];
		
		// printf("%ld %ld\n", x, y);
		if (m.find(y) == m.end()) {
			m[y] = {c[0], c[0]};
		} else {
			m[y].first = min(m[y].first, x);
			m[y].second = max(m[y].second, x);
		}
	}
	
	// dp[y] = {x1, minSteps if snake eats on row y last  (x1, y), x2, minSteps if snakes east last on row y  (x2, y)}
	map<long, vector<long>> dp;
	dp[1] = {1, 2 * (m[1].second - m[1].first), m[1].second, m[1].second - m[1].first};
	long prevY = -1;
	for (auto kv : m) {
		long y = kv.first;
		long x1 = kv.second.first;
		long x2 = kv.second.second;
		if (y != 1) {
			// vertical distance between cur row and prev row.
			auto h = y - prevY;
			dp[y] = {
				x1, 
				h + min(
						distLeft(dp[prevY][0], x1, x2) + dp[prevY][1], 
						distLeft(dp[prevY][2], x1, x2) + dp[prevY][3]), 
				x2,
				h + min(
						distRight(dp[prevY][0], x1, x2) + dp[prevY][1],
						distRight(dp[prevY][2], x1, x2) + dp[prevY][3])	
			};
		}

		prevY = y;
	}
	
	return min(dp[prevY][1], dp[prevY][3]);
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

	out << solve(v) << endl;
    }

    in.close();
    out.close();
    return 0;
}
