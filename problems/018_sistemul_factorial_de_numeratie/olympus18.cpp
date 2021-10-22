#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

int main() {
	ifstream in("in1.txt");
	int n;
	in >> n;
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