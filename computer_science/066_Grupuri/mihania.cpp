#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<unordered_map>
#include<set>
#include<unordered_set>

using namespace std;

// converts set<int> to a string representation.
string toString(set<int> s) {
	string res;
	for (auto k : s) {
		res += "|" + to_string(k);
	}

	return res;
}

int solve(vector<vector<string>> catalogs) {
	// maps userId -> catalogId* (ordered)
	unordered_map<string, set<int>> m;
	for (int i = 0; i < catalogs.size(); i++) {
		for (auto& c : catalogs[i]) {
			m[c].insert(i);
		}
	}	

	
	// set of different ordered catalogIds
	unordered_set<string> sets;
	for (auto& kv : m) {
		sets.insert(toString(kv.second));
		printf("%s -> %s\n", kv.first.c_str(), toString(kv.second).c_str());
	}

	return sets.size();
}

int main() {
    ifstream in("tests.in");
    ofstream out("tests.out");
    long T;
    in >> T;
    for (auto t = 0; t < T; t++) {
        int users;
	in >> users;
	vector<vector<string>> catalogs;
	for (int i = 0; i < users; i++) {
		int catalogsCount;
		in >> catalogsCount;
		vector<string> v;
		for (int j = 0; j < catalogsCount; j++) {
			string s;
			in >> s;
			v.push_back(s);
		}

		catalogs.push_back(v);
	}
	
	out << solve(catalogs) << endl;
    }

    in.close();
    out.close();
} 
