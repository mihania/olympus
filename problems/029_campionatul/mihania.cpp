#include<fstream>
#include<vector>
#include<map>
#include<numeric>
#include<set>
using namespace std;

map<long long, long long> getMap(long long S, vector<long long>& c) {
	map<long long, long long> m;
    	m[0] = 1;
    	for (auto k : c) {
		vector<long long> values;
	       	long long prev = -1;
		for (auto it = m.rbegin(); it != m.rend(); it++) {
			
			// inserting a new element in the map changes the iterator order. dirty fix to not go 
			// over the same element again.
			auto i = it->first;
			if (prev == i) {
				continue;
			}

			prev = i;
			
			if (i + k <= S) {
			 	m[i + k] += m[i];	
			}
		}	
    	}
	
	return m;
}

map<long long, long long> getMap2N(long long S, vector<long long>& c) {
	map<long long, long long> res;
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
			// printf("\tmask=%lld idx=%d\n", mask, idx);
		}

		if (sum <= S) {
			res[sum]++;
		}

		// printf("mask=%lld sum=%lld\n", mask, sum);
	}

	return res;
}

long long solve(long long S, vector<long long>& c2) {
	vector<long long> c;
	
	// filter out elements greater than S
	copy_if(c2.begin(), c2.end(), back_inserter(c), [S](long i) { return i <= S; });
	
	// S cannot be bigger than sum of tickets
	S = min(S, accumulate(c.begin(), c.end(), (long long)0));

	sort(c.begin(), c.end());

	vector<long long> odd;
	vector<long long> even;
	for (int i = 0;i < c.size(); i++) {
		if (i % 2 == 0) {
			even.push_back(c[i]);
		} else {
			odd.push_back(c[i]);
		}
	}

	map<long long, long long> evenM = getMap2N(S, even);
	map<long long, long long> oddM = getMap2N(S, odd);
	long long res = 0;
	for (auto i : evenM) {
		for (auto j : oddM) {
			if (i.first + j.first <= S) {
				res += i.second * j.second;
			}
		}
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
		
		printf("i=%d N=%lld S=%lld\n", i, N, S);
		long long res = solve(S, c);
		out << res << endl;
		printf(" res=%lld\n", res);
	}


	in.close();
	out.close();
	return 0;
}
