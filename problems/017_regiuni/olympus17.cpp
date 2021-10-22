#include<vector>
#include<unordered_map>
#include<stack>
#include<iostream>
#include<fstream>

using namespace std;

unordered_map<int, vector<int>> paths;
int components[7];
int numComponents;
stack<int> orderVertices;
bool marked[7];

void dfs(int v, unordered_map<int, vector<int>> revPaths) {
	marked[v] = true;
	if (revPaths.find(v) != revPaths.end()) {
		for (int i : revPaths[v]) {
			if (!marked[i]) {
				dfs(i, revPaths);
			}
		}
		orderVertices.push(v);
	}
	else {
		orderVertices.push(v);
	}
}

void findOrderVertices(unordered_map<int, vector<int>> p) {
	unordered_map<int, vector<int>> revPaths;
	for (int i = 1; i <= p.size(); i++) {
		vector<int> listI = p[i];
		for (int j : listI) {
			if (revPaths.find(j) != revPaths.end()) {
				revPaths[j].push_back(i);
			}
			else {
				vector<int> l;
				l.push_back(i);
				revPaths.insert({j, l});
			}
		}
	}
	for (int i = 1; i < sizeof(marked); i++) {
		if (!marked[i]) {
			dfs(i, revPaths);
		}
	}
}

void dfs(int v) {
	components[v] = numComponents;
	if (paths.find(v) != paths.end()) {
		for (int w : paths[v]) {
			if (components[w] == -1) {
				dfs(w);
			}
		}
	}
}

int findStronglyConnectedComponents() {
	findOrderVertices(paths);
	//order vertices is true
	numComponents = 0;
	while (!orderVertices.empty()) {
		int i = orderVertices.top();
		orderVertices.pop();
		if (components[i] == -1) {
			dfs(i);
			numComponents++;
		}
	}
	return numComponents;
}

int main() {
	ifstream in("city6.txt");
	int n;
	in >> n;
	cout << n;
    for (int i = 1; i < n; i++) {
        components[i] = -1;
    }
    for (int i = 1; i < n; i++) {
		vector<int> vec;
        paths[i] = vec;
    }
	while (true) {
		int a;
		int b;
		in >> a;
		in >> b;
		if (a == 0 || b == 0) break;
		paths[a].push_back(b);
	}
	findStronglyConnectedComponents();
	//cout << "numComponents = " << numComponents << endl;
    ofstream out("res.txt");
	out << numComponents;
	in.close();
	out.close();
    
    cout << "Program is done.\n";
}