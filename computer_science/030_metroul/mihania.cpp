#include<fstream>
#include<vector>
#include<sstream>
#include<unordered_set>
#include<queue>
#include<tuple>

using namespace std;

class Test {
public:
	long N;
	long M;
	long X;
	long Y;
	vector<vector<long>> V;
};


// mapping between vertex -> line*
vector<unordered_set<long>> getLines(Test& test) {
	vector<unordered_set<long>> res(test.M + 1, unordered_set<long>());
	for (int i = 0; i < test.V.size(); i++) {
		for (long j : test.V[i]) {
			res[j].insert(i);
		}
	}

	return res;
}

long solve(Test& test) {
	auto lineMap = getLines(test);
	queue<tuple<long, long, long>> q;
	
	// m[i] - the distance from X station to i-th station.
	vector<long> m(test.M + 1, test.M);
	
	// station, lineChanges, currentLine
	q.push({test.X, -1, -1});
	
	m[test.X] = 0;
	while (!q.empty()) {
		long v = get<0>(q.front());
		long dist = get<1>(q.front());
		long currentLine = get<2>(q.front());
		q.pop();
		unordered_set<long> lines = lineMap[v];
		for (long lineId : lines) {
			for (long w : test.V[lineId]) {
				long newDist = dist + (lineId == currentLine ? 0 : 1); 
				if (newDist < m[w]) {
					q.push({w, newDist, lineId});
					m[w] = newDist;
				}
			}
		}

	}

	return m[test.Y];
}

int main() {
	ifstream in("tests.in");
	int T;
	in >> T;
	
	ofstream out("tests.out");
	for (int i = 0; i < T; i++) {
		Test test;
		in >> test.N;
		in >> test.M;
		in >> test.X;
		in >> test.Y;
	        
		string newLine;
		getline(in, newLine);
		for (int j = 0; j < test.N; j++) {
			string line;
			getline(in, line);
			stringstream ss(line);
			string numStr;
			test.V.push_back(vector<long>());
			while (ss >> numStr) {
				long num = stol(numStr);
				test.V[j].push_back(num);
			}
		}
		
		out << solve(test) << endl;
	}

	in.close();
	out.close();
	return 0;
}
