#include<fstream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
#include<iostream>

using namespace std;

int dppp[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 

class Test {
public:
    vector<vector<char>> z;
    vector<vector<long>> h;
    pair<int, int> P;
    long N;
};

template <typename T>
void printf(vector<vector<T>>& m) {
    for (auto& v : m) {
        for (auto k : v) {
            cout << k << " ";
        }
        
        printf("\n");
    }

    printf("\n");
}

// O(n^2)
bool canReach(Test& t, long houseCount, long minH, long maxH) {
    vector<vector<bool>> visited(t.N, vector<bool>(t.N, false));

    long count = 0;    
    if (t.h[t.P.first][t.P.second] >= minH && t.h[t.P.first][t.P.second] <=  maxH) {
        queue<tuple<int, int>> q;
        q.push({t.P.first, t.P.second});
        visited[t.P.first][t.P.second] = true;
        while (!q.empty() && count < houseCount) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            q.pop();
        
            for (auto& dpp : dppp) {
                int ni = i + dpp[0];
                int nj = j + dpp[1];
                if (ni >= 0 && ni < t.N && nj >= 0 && nj < t.N
                        && !visited[ni][nj] 
                        && t.h[ni][nj] >= minH && t.h[ni][nj] <= maxH) {
                
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                    if (t.z[ni][nj] == 'K') {
                        count++;
                    }
                }   
            }
        }
    }

    // printf("\tcanReach(houseCount=%ld interval=%ld minH=%ld maxH=%ld) count=%ld\n", houseCount, maxH - minH, minH, maxH, count);
    return count == houseCount;
}

// O(h * n^2)
bool canReach(Test& t, long houseCount, long interval, long minH, long maxH) {
    bool res = false;
    for (int i = minH; i + interval <= maxH; i++) {
        if (canReach(t, houseCount, i, i + interval)) {
            res = true;
            break;
        }
    }

    // printf("canReach houseCount=%ld interval=%ld minH=%ld maxH=%ld res=%d\n", houseCount, interval, minH, maxH, res);
    return res;
}

// O(log(h) * h * n^2)
long solveV2(Test& t) {
    // getting some statistics
    long maxH = 0;      // the max height of all cells
    auto minH = LONG_MAX;   // the min height of all cells
    long count = 0;     // number of houses.
    for (auto i = 0; i < t.h.size(); i++) {
        for (auto j = 0; j < t.h.size(); j++) {
            if (t.z[i][j] == 'K') {
                count++;
            }
            
            minH = min(minH, t.h[i][j]);
            maxH = max(maxH, t.h[i][j]);
        }
    }


    // binary searh on min interval size that is enough to get to all houses.
    auto i = 0;     // min interval size is 0
    auto j = maxH - minH; // max interval size cannot be bigger than difference between max and min cell.
    while (i < j) {
        auto mid = i + (j - i) / 2;
        if (canReach(t, count, mid, minH, maxH)) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }

    return j;
}

int main() {
    ifstream in("tests.in");
    int T;
    in >> T;
    ofstream out("tests.out");
    for (int t = 0; t < T; t++) {
        Test test;
        in >> test.N;
        for (int i = 0; i < test.N; i++) {
            vector<char> zCur;
            for (int j = 0; j < test.N; j++) {
                char ch;
                in >> ch;
                zCur.push_back(ch);
                if (ch == 'P') {
                    test.P = {i, j};
                }
            }

            test.z.push_back(zCur);
        }

        for (int i = 0; i < test.N; i++) {
            vector<long> hCur;
            for (int j = 0; j < test.N; j++) {
                long v;
                in >> v;
                hCur.push_back(v);
            }

            test.h.push_back(hCur);
        }

        // if (t == 3) 
        {
            auto res = solveV2(test);
            cout << res << endl;
            out << res << endl;
        }
    }

    in.close();
    out.close();
    return 0;
}

