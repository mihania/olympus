#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

int toNum(unordered_map<char, int> m, string s) {
    if (s.size() == 1) {
        return m[s[0]];
    }
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 <= s.size() - 1 && m[s[i]] >= m[s[i + 1]]) {
            res += m[s[i]];
        }
        if (i + 1 <= s.size() - 1 && m[s[i]] < m[s[i + 1]]) {
            res += m[s[i + 1]] - m[s[i]];
            i++;
        }
        if (i + 1 == s.size() - 1) {
            res += m[s[i + 1]];
        }
    }
    return res;
}

int main() {
    ifstream in("expresii.in");
    ofstream out("expresii.out");
    string s;
    in >> s;
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int idx = 0;
    vector<string> subs; //substrings without multiplication
    vector<char> signs;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            subs.push_back(s.substr(idx, i - idx));
            signs.push_back('+');
            idx = i + 1;
        }
        if (s[i] == '-') {
            subs.push_back(s.substr(idx, i - idx));
            signs.push_back('-');
            idx = i + 1;
        }
        if (i == s.size() - 1) {
            subs.push_back(s.substr(idx, i - idx + 1));
        }
    }
    int res = 0;
    for (int i = 0; i < subs.size(); i++) {
        idx = 0;
        int num = 0;
        for (int j = 0; j < subs[i].size(); j++) {
            if (subs[i][j] == '*') {
                if (num == 0) {
                    num += toNum(m, subs[i].substr(idx, j - idx));
                    idx = j + 1;
                }
                else {
                    num *= toNum(m, subs[i].substr(idx, j - idx));
                }
            }
            if (j == subs[i].size() - 1) {
                if (num == 0) {
                    num += toNum(m, subs[i].substr(idx, j - idx + 1));
                }
                else {
                    num *= toNum(m, subs[i].substr(idx, j - idx + 1));
                }
            }
        }
        if (i == 0) {
            res = num;
        }
        else {
            if (signs[i - 1] == '+') {
                res += num;
            }
            else {
                res -= num;
            }
        }
    }

    out << res << endl;
}
