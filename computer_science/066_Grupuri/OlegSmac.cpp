#include<vector>
#include<iostream>
#include<fstream>
#include<unordered_map>

using namespace std;

bool contains(vector<vector<int>>& res, vector<int>& v) {
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() == v.size()) {
            for (int j = 0; j < res[i].size(); j++) {
                if (res[i][j] != v[j]) {
                    break;
                }
                if (j == res[i].size() - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int solution(vector<vector<int>>& people) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < people[i].size(); j++) {
            m[people[i][j]].push_back(i);
        }
    }
    vector<vector<int>> res;
    for (auto it = m.begin(); it != m.end(); it++) {
        auto num = it -> first;
        auto v = it -> second;
        if (!contains(res, v)) {
            res.push_back(v);
        }
    }
    return res.size();
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
    int T;
    in >> T;
    for (int i = 0; i < T; i++) {
        int n;
        in >> n;
        vector<vector<int>> people;
        for (int j = 0; j < n; j++) {
            int num;
            in >> num;
            vector<int> v;
            for (int x = 0; x < num; x++) {
                int man;
                in >> man;
                v.push_back(man);
            }
            people.push_back(v);
        }
        cout << solution(people) << endl;
    }

	in.close();
	out.close();
}
