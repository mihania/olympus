#include<fstream>
#include<vector>
#include<numeric>
using namespace std;

vector<long> getSums(long S, vector<long>& c) {
	vector<long> res;
	long max = (long)pow(2, c.size());
	for (long k = 0; k < max; k++) {
		long sum = 0;
		int idx = 0;
		auto mask = k;
		while (mask > 0) {
			if (mask % 2 == 1) {
				sum += c[idx];
			}

			mask /= 2;
			idx++;
		}

		if (sum <= S) {
			res.push_back(sum);
		}

	}

	return res;
}

long solve(long S, vector<long>& c) {
	
	// splitting array into two equal subarrays
	auto v1 = vector<long>(c.begin(), c.begin() + c.size() / 2);
	auto v2 = vector<long>(c.begin() + c.size() / 2, c.end());

	// calculating all possible subset sums in each array
	auto s1 = getSums(S, v1);
	auto s2 = getSums(S, v2);
	
	// merging arrays subset sums
	sort(s2.begin(), s2.end());
	long res = 0;
	for (auto k : s1) {
		auto it = upper_bound(s2.begin(), s2.end(), S - k);
		res += it - s2.begin();
	}

	return res;
}

int main() {
	ifstream in("tests.in");
	int T;
	in >> T;

	ofstream out("tests.out");
	for (auto i = 0; i < T; i++) {
		long N;
		long S;
		vector<long> c;
		in >> N;
		in >> S;
		for (auto j = 0; j < N; j++) {
			long v;
			in >> v;
			c.push_back(v);
		}
		
		out << solve(S, c) << endl;
	}


	in.close();
	out.close();
	return 0;
}

