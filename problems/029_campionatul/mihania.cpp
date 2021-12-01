#include<fstream>
#include<vector>
#include<map>
#include<numeric>
#include<set>
using namespace std;

long long solve(const long long N, long long S, vector<long long>& c2) {
	vector<long long> c;
	
	// filter out elements greater than S
	copy_if(c2.begin(), c2.end(), back_inserter(c), [S](long i) { return i <= S; });
	
	// S cannot be bigger than sum of tickets
	S = min(S, accumulate(c.begin(), c.end(), (long long)0));
	
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

    	long long res = 0;
	for (auto it : m) {
		res += it.second;
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
		long long res = solve(N, S, c);
		out << res << endl;
		printf(" res=%lld\n", res);
	}


	in.close();
	out.close();
	return 0;
}
