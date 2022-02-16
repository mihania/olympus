#include<vector>
#include<iostream>
#include<fstream>
#include<unordered_map>

using namespace std;

// string representation of prev and mask.
string getKey(int* prev, int mask) {
	return (prev == nullptr ? "" : to_string(*prev)) + "|" + to_string(mask);
}

// true if index i is used in mask, otherwise false.
bool isUsed(int i, int mask) {
	return ((1 << i) & mask) != 0;
}

// returns the new mask after setting i-th bit in mask to 1.
int setUsed(int i, int mask) {
	return mask | (1 << i);
}

// returns a new mask after unsetting i-th bit in mask.
int setUnUsed(int i, int mask) {
	return mask & ~(1 << i);
}


// prev - the value of previous domino in chain or nullptr if chain is empty
// mask - identifies used and unused dominos in the chain. mask is 32-bit integer, 
//        where each bit set to 1 identifies that domino v[i] is used).
//        instead of bitwise operations unordered_set<int> can be used.
// dp[key] - shows the longest path of dominos that can be formed for the key. key is a a tuple of prev and mask.
int dfs(vector<vector<int>>& v, int* prev, int mask, unordered_map<string, int> dp) {
	string key = getKey(prev, mask);
	if (dp.find(key) == dp.end()) {
		int maxRes = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!isUsed(i, mask) 
					&& (prev == nullptr || *prev == v[i][0] || *prev == v[i][1])) {
				mask = setUsed(i, mask);
				int res = 1;
				if (prev == nullptr) {
					res += max(dfs(v, &v[i][0], mask, dp), dfs(v, &v[i][1], mask, dp));
				} else {
					res += dfs(v, *prev == v[i][0] ? &v[i][1] : &v[i][0], mask, dp);
				}

				mask = setUnUsed(i, mask);
				maxRes = max(maxRes, res);
			}
		}

		dp[key] = maxRes;
	}

	return dp[key];
}


/** 
 * this problem is NP-hard (finding the longest path in the graph https://en.wikipedia.org/wiki/Longest_path_problem)
 * which means it cannot be solved in polynomial time.
 * The current approach is brute force on trying all possible permutations with mask memoization 	
 */
int solve(vector<vector<int>>& v) {
	unordered_map<string, int> dp;
	return dfs(v, nullptr, 0, dp); 
}

int main() {
    ifstream in("tests.in");
    ofstream out("tests.out");
    int n;
    in >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
    	vector<int> d;
	int val;
	in >> val;
	d.push_back(val);
	in >> val;
	d.push_back(val);
	v.push_back(d);
    } 

    out << solve(v) << endl; 
    in.close();
    out.close();
} 
