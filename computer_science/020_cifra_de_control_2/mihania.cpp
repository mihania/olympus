#include<iostream>
#include<fstream>

using namespace std;

int main() {

	// let A = a0 + 10a1 + 10^2 * a2 + ... 
	// A % 9 = (a0 + (9 + 1)a1 + (99 + 1)a2 +...) % 9 = (a0 + a1 + a2+ ..) % 9
	// => A % 9 = (a0 + a1 + a2 + .. aN) %9
	// let dp[n][k] = count of numbers of length n which control sum is k
	// dp[n][k] = dp[n - 1][k] * 10
	// => M = 10^(n - 1)
	ifstream in("in.txt");
	long n;
	in >> n;
	ofstream out("out.txt");
	out << 1;
	for (int i = 0; i < n - 1; i++) {
		out << 0;
	}

	out << endl;
	in.close();
	out.close();
}
