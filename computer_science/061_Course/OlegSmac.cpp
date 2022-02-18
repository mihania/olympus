#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<cmath>

using namespace std;

int solution1(vector<vector<int>>& intervals, int n, int K) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    for (int p = 0; p < intervals.size(); p++) {
        cout << intervals[p][0] << " " << intervals[p][1] << endl;
    }

    if (intervals.size() <= K) {
        return intervals.size();
    }

    int maxLen = 0;
    for (vector<int>& v : intervals) {
        maxLen = max(maxLen, v[1]);
    }

    //dp[i][j] - длина максимальной подпоследовательности на интервале [0, i],
    //если i-я подпоследовательность входит в j пересечений


	return -1;
}

bool check_intersections(vector<vector<int>>& intervals, int mid, int k) {
    bool can = true;
    int intersections = 0;
    for (int i = 0; i < intervals.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (intervals[j][0] + mid > intervals[i][0]) {
                //cout << "j = " << intervals[j][0] << " mid = " << mid << " i = " << intervals[i][0];
                intersections++;
                //cout << " inter = " << intersections << endl;
            }
        }

        if (intersections >= k) {
            can = false;
            break;
        }
    }
    return can;
}

int solution2(vector<vector<int>>& intervals, int n, int k) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    int maxCurs = 0;
    for (int i = 0; i < intervals.size(); i++) {
        maxCurs = max(maxCurs, intervals[i][1] - intervals[i][0]);
    }

    int res = 0;
    int low = 0;
    int high = maxCurs;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        //если меньше k пересечений (начало интервала + mid)
        bool can = check_intersections(intervals, mid, k);

        if (can) {
            res = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
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
        vector<vector<int>> intervals;
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
        if (C == 1) {
            cout << solution1(intervals, n, k) << endl;
            cout << endl;
        }
        else if (C == 2) {
            cout << solution2(intervals, n, k) << endl;
        }
	}


	in.close();
	out.close();
}
