#include<vector>
#include<unordered_map>
#include<stack>
#include<iostream>
#include<fstream>

using namespace std;

unordered_map<int, vector<int>> paths;
int components[6];
int numComponents;

int main() {
	ifstream in("city6.txt");
	int n;
	in >> n;
    for (int i = 1; i < n; i++) {
        components[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        paths.insert({i, vector<int> vec});
    }
	while (true) {
		int a;
		int b;
		in >> a;
		in >> b;
		if (a == 0 || b == 0) break;
		paths.get(a).add(b);
	}
    ofstream out("city6res.txt");
	out << numComponents;
	in.close();
	out.close();
    
    std::cout << "Hello World!\n";
}