#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<unordered_set>

using namespace std;

string numsOutput(unordered_set<int>& nums) {
    string res;
    for (int i = 1; i <= 9; i++) {
        if (nums.count(i) == 1) {
            res += i + '0';
        }
        if (res.size() == 1 && nums.count(0) == 1) {
            res += '0';
        }
    }
    return res;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		int n;
		in >> n;
        string letters;
        unordered_set<int> nums;
        for (int j = 0; j < n; j++) {
            char c;
            in >> c;
            if (c >= '0' && c <= '9' && nums.count(c - '0') == 0) {
                nums.insert(c - '0');
            }
            else if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
                letters += c;
            }
            else if (c >= 'A' && c <= 'Z') {
                letters += c;
            }
        }
        out << letters << endl;
        out << numsOutput(nums) << endl;
	}

	in.close();
	out.close();
}
