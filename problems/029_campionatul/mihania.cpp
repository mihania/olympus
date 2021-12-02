#include<fstream>
#include<vector>
#include<map>
#include<numeric>
#include<set>
using namespace std;

void printf(vector<long long>& v) {
	return;
	for (auto k : v) {
		printf("%lld ", k);
	}

	printf("\n");
}

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

long long solve(long long S, vector<long long>& c2) {
	vector<long long> c = c2;
	/*
	
	// filter out elements greater than S
	copy_if(c2.begin(), c2.end(), back_inserter(c), [S](long i) { return i <= S; });
	
	// S cannot be bigger than sum of tickets
	S = min(S, accumulate(c.begin(), c.end(), (long long)0));
	*/

	vector<long long> v1 = vector<long long>(c.begin(), c.begin() + c.size() / 2);
	vector<long long> v2 = vector<long long>(c.begin() + c.size() / 2, c.end());

	printf(v1);
	printf(v2);	
	auto s1 = getSums(S, v1);
	auto s2 = getSums(S, v2);
	
	sort(s2.begin(), s2.end());
	
	// erasing empty set from the second array
	s2.erase(s2.begin());
	printf(s1);
	printf(s2);

	long long res = 0;
	for (auto k : s1) {
		auto it = upper_bound(s2.begin(), s2.end(), S - k);
		// if (it != s2.end()) 
		{
			res += 1 + (it - s2.begin());
		}

		// printf("k=%lld res=%lld\n", k, res);	
	}

	return res;
}

int main() {
	ifstream in("tests.in");
	int T;
	in >> T;

	ofstream out("tests.out");
	for (auto i = 0; i < T; i++) {
		// if (i != 0) break;

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
		
		printf("i=%d N=%lld S=%lld\n", i, N, S);
		long long res = solve(S, c);
		out << res << endl;
		printf(" res=%lld\n", res);
	}


	in.close();
	out.close();
	return 0;
}
