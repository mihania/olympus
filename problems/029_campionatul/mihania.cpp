#include<fstream>
#include<vector>
#include<unordered_map>
#include<numeric>

using namespace std;

long solve(const long N, long S, vector<long>& c2) {
	vector<long> c;
	
	// filter out elements greater than S
	copy_if(c2.begin(), c2.end(), back_inserter(c), [S](long i) { return i <= S; });
	
	// S cannot be bigger than sum of tickets
	S = min(S, accumulate(c.begin(), c.end(), (long)0));
	
	// m[i][j] - number of different tickets to buy with i money if we have only j tickets
	unordered_map<long, unordered_map<int, long>> m;	

	// 1 - is the empty set.
	long res = 1;
	for (long i = 0; i <= S; i++) {
		for (int j = 0; j < c.size(); j++) {
			long sum = 0;

			// if we don't take the coin.
			if (j > 0 &&  m[i][j - 1] > 0) {
				m[i][j] += m[i][j - 1];
			}

			// if we take the coin and add to previous subset
			if (j > 0 && c[j] <= i) {
				sum += m[i - c[j]][j - 1];
			}	
			
			// if we just take the coin by itsef {j}
			if (i == c[j]) {
				sum += 1;
			}	

			if (sum > 0) {
				res += sum;
				m[i][j] += sum;
			//	printf("[%ld, %d]=%ld\n", i, j, sum);
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
	for (int i = 0; i < T; i++) {
		long N;
		long S;
		vector<long> c;
		in >> N;
		in >> S;
		for (int j = 0; j < N; j++) {
			int v;
			in >> v;
			c.push_back(v);
		}
		
		// if (i < 10) 
		{
			printf("i=%d N=%ld S=%ld", i, N, S);
			long res = solve(N, S, c);
			out << res << endl;
			printf(" res=%ld\n", res);
		}
	}


	in.close();
	out.close();
	return 0;
}
