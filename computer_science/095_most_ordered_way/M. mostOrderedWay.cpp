#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
#include <array>

using namespace std;

int main() {
    int n; cin >> n;

    vector<array<int, 3>> tasks(n);

    for (int i = 0; i < n; i++) {
        int t, d; cin >> t >> d;
        tasks[i] = {d, t, i};
    }

    sort(tasks.begin(), tasks.end());

    int sum = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (sum + tasks[i][1] > tasks[i][0]) {
            cout << "*" << endl;
            return 0;
        }
        sum += tasks[i][1];
    }

    int now = 0;
    while (!tasks.empty()) {
        int j = -1;
        int rest = 1e9 + 1;
        int s2 = now;
        for (int i = 0; i < tasks.size(); i++) {
            if (rest >= tasks[i][1] && (j == -1 || tasks[i][2] < tasks[j][2])) {
                j = i;
            }
            s2 += tasks[i][1];
            rest = min(rest, tasks[i][0] - s2);
        }
        now += tasks[j][1];
        cout << tasks[j][2] + 1 << " ";
        tasks.erase(tasks.begin() + j);
    }

    return 0;
}
