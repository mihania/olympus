#include<fstream>
#include<vector>
#include<numeric>
using namespace std;

vector<long long> getSums(long long S, vector<long long>& c) {
	vector<long long> res;
	long long max = (long long)pow(2, c.size());
	for (long long k = 0; k < max; k++) {
		long long sum = 0;
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

long long solve(long long S, vector<long long>& c) {
	
	// splitting array into two equal subarrays
	auto v1 = vector<long long>(c.begin(), c.begin() + c.size() / 2);
	auto v2 = vector<long long>(c.begin() + c.size() / 2, c.end());

	// calculating all possible subset sums in each array
	auto s1 = getSums(S, v1);
	auto s2 = getSums(S, v2);
	
	sort(s2.begin(), s2.end());
	
	// erasing empty set from the second array
	s2.erase(s2.begin());

	// merging arrays subset sums
	long long res = 0;
	for (auto k : s1) {
		auto it = upper_bound(s2.begin(), s2.end(), S - k);
		res += 1 + (it - s2.begin());
	}

	return res;
}

int main() {
	ifstream in("tests.in");
	int T;
	in >> T;

	ofstream out("tests.out");
	for (auto i = 0; i < T; i++) {
		long long N;
		long long S;
		vector<long long> c;
		in >> N;
		in >> S;
		for (auto j = 0; j < N; j++) {
			long long v;
			in >> v;
			c.push_back(v);
		}
		
		out << solve(S, c) << endl;
	}


	in.close();
	out.close();
	return 0;
}
