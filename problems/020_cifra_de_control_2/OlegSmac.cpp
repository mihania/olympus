#include<iostream>
#include<fstream>
#include<math.h>
#include<array>

using namespace std;

int main() {
	ifstream in("in45.txt");
	long n;
	int k;
	string M;
	in >> n;
	in >> k;
	//375 = 15 = 6
	//an, a(n - 1) .. a2, a1, a0;
	//(a0 + 10 * a1 + 100 * a2 + .. 10^n * an) % 9 = (a0 + a1 + .. + an) % 9;
	//a0 + (1 + 9) * a1 + (1 + 99) * a2 ...
	//(a0 + a1 + 9a1 + a2 + 99a2 ...) % 9
	//(a0 + a1 + 0 + a2 + 0 ...) % 9
	//array dp[n + 1][10] (int)
	//dp[i][j] - количество чисел, длиной i и остатком деления на 9, равное j. 
	//dp[n][k] - решение
	M = "1";
	for (int i = 0; i < n - 1; i++) {
		M += "0";
	}
	cout << "M = " << M << endl;
	ofstream out("res.txt");
	out << M;
	in.close();
	out.close();
    
    cout << "Program is done.\n";
}