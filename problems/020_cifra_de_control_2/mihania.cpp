#include<iostream>
#include<fstream>

using namespace std;

int main() {
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
