#include<fstream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
#include<iostream>
#include<unordered_set>

using namespace std;

int dppp[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 
long complexity = 0;

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


template <typename T>
void printf(vector<T>& m) {
    for (auto& v : m) {
        cout << v << " ";
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
        
            for (const auto& dpp : dppp) {
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
                
                complexity++;
            }
        }
    }

    // printf("\tcanReach(houseCount=%ld interval=%ld minH=%ld maxH=%ld) count=%ld\n", houseCount, maxH - minH, minH, maxH, count);
    return count == houseCount;
}

// O(log(h) * n^3), slow but works.
long solve(Test& t) {
    complexity = 0;

    vector<long> heights; // unique heights of all cells sorted in ascending order.
    long houseCount = 0;
    for (auto i = 0; i < t.h.size(); i++) {
        for (auto j = 0; j < t.h.size(); j++) {
            if (t.z[i][j] == 'K') {
                houseCount++;
            }
            
	    heights.push_back(t.h[i][j]);
        }
    }

    // sorting heights and removing duplicates
    sort(heights.begin(), heights.end());
    auto ip = unique(heights.begin(), heights.end());
    heights.resize(distance(heights.begin(), ip));
    // printf(heights);
    long res = heights[heights.size() - 1] - heights[0];;
    for (int i = 0; i < heights.size(); i++) {
    	int start = i;
	// int end = distance(heights.begin(), lower_bound(heights.begin(), heights.end(), heights[i] + res)) - 1;	    
	int end = heights.size() - 1;
	while (start < end) {
		// printf("\ti=%d start=%d end=%d heights[start]=%ld heights[end]=%ld\n", i, start, end, heights[start], heights[end]);
		int mid = start + (end - start) / 2;
		if (canReach(t, houseCount, heights[i], heights[mid])) {
			end = mid;
			res = min(res, heights[mid] - heights[i]);
		} else {
			start = mid + 1;
		}
	
	}
	
	// printf("i=%d start=%d end=%d res=%ld\n", i, start, end, res);
    }

    return res;
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

	if (t != 1) {
	// 	continue;
	}

        auto res = solve(test);
        cout << res << endl;
        out << res << endl;
    }

    in.close();
    out.close();
    return 0;
}

