#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

int main() {
	ifstream in("in2.txt");
	cout << "3 / 4 = " << 3/4 << " 3 % 4 = " << 3%4 << endl; 
	int n;
	in >> n;
	//n = num1 * 1! + num2 * 2! + num3 * 3! + ... + numn * n!;
	//n! = 1 * 2 * 3 * ... * n;
	//n = num1 * 1 + num2 * (1 * 2) + num3 * (2 * 3) + ... + numn * (1 * 2 * ... * n);
	//n % 2 = num1 * 1 % 2 + 0 + 0;
	//n / 2 = num1 * 1/2 + num2 * 1 + num3 * 3 + ... + numn * (1 * 3 * ... * n);
	//n % 3 = num1 * 1/2 % 3 + num2 * 1 % 3 + 0 + 0;
	//n / 3 = num1 * 1/6 + num2 * 1/3 + num3 * 1 + ... + numn * (1 * 4 * ... * n);
	//
	cout << "n = " << n << endl; 
	stack<int> stack;
	for (int i = 2; n != 0; i++) {
		stack.push(n % i);
		n = n / i;
	}
	int res = 0;
	while (!stack.empty()) {
		int num = stack.top();
		cout << "num = " << num << endl;
		res = res * 10 + num;
		stack.pop();
	}
	ofstream out("res.txt");
	out << res;
	in.close();
	out.close();
}