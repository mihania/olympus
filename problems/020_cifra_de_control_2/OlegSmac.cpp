#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int findSumDigits(long num) {
	if (num / 10 == 0) return num;
	//cout << "num = " << num;
	long sum = 0;
	while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}
	//cout << " sum = " << sum << endl;
	return findSumDigits(sum);
} 

int myPow(long n) {
	long res = 10;
	for (int i = 2; i <= n; i++) {
		res = res * 10;
	}
	return res;
}

int main() {
	ifstream in("in23.txt");
	long n;
	int k;
	int M = 0;
	in >> n;
	in >> k;
	long start = myPow(n - 1);
	long end = myPow(n); 
	//cout << "start = " << start << " end = " << end << endl;
	for (long i = start; i < end; i++) {
		if (findSumDigits(i) == k) {
			M++;
		}
	}
	cout << "M = " << M << endl;
	ofstream out("res.txt");
	out << M;
	in.close();
	out.close();
    
    cout << "Program is done.\n";
}