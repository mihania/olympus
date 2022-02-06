#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<cmath>

using namespace std;

int solution(vector<vector<int>>& intervals, int n, int k) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    int maxLen = 0;
    for (int i = 0; i < intervals.size(); i++) {
        maxLen = max(maxLen, intervals[i][1]);
    }

    int res = 0;
    int low = 0;
    int high = maxLen;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        bool can = true;
        for (int i = 0; i <= maxLen; i++) {
            int num = 0;
            for (int j = 0; j < intervals.size(); j++) {
                if (intervals[j][0] < i && intervals[j][0] + mid >= i) {
                    num++;
                }
            }
            if (num > k) {
                can = false;
                break;
            }
        }

        if (!can) {
            high = mid - 1;
        }
        else if (can && mid > res) {
            low = mid + 1;
            res = mid;
        }
    }
    return res;
}

int main() {
	ifstream in("tests.in");
	ofstream out("res.txt");
	int T;
	in >> T;
	vector<vector<int>> intervals;
	for (int i = 0; i < T; i++) {
        int C;
        int n;
        int k;
        in >> C >> n >> k;
        for (int j = 0; j < n; j++) {
            vector<int> v;
            int num;
            in >> num;
            v.push_back(num);
            in >> num;
            v.push_back(num);
            intervals.push_back(v);
        }
        if (C == 2) {
            cout << solution(intervals, n, k);
        }
	}


	in.close();
	out.close();
}
