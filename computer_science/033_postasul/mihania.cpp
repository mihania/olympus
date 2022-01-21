#include<fstream>
#include<vector>
#include<tuple>
#include<cmath>
#include<queue>
#include<iostream>
#include <ctime>

using namespace std;

int dppp[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 

class Test {
public:
    vector<vector<char>> z;
    vector<vector<long>> h;
    pair<int, int> P;
    long N;
};


// O(8 * n^2)
bool canReachAllHouses(Test& t, long houseCount, long minH, long maxH) {
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
            }
        }
    }

    return count == houseCount;
}

// O(8 * log(h) * n^4), slow but works.
long solve(Test& t) {
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
    
    // removing duplicates
    auto ip = unique(heights.begin(), heights.end());
    
    // resizing heights after duplicates removal
    heights.resize(distance(heights.begin(), ip));
    
    // best window cannot be bigger than maximum distance between all cells.
    long res = heights[heights.size() - 1] - heights[0];
    for (auto i = 0; i < heights.size(); i++) {

	// binary searching minimum end for the given heights[i]
    	auto start = i;
	
	// we don't need to consider end greater than min occurence of heights[i] + res, as it will be worse than the previous res.
	auto end = distance(heights.begin(), lower_bound(heights.begin(), heights.end(), heights[i] + res));
	auto maxEnd = end;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (canReachAllHouses(t, houseCount, heights[i], heights[mid])) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}

	if (end == maxEnd) {
		if (maxEnd == heights.size()) {
			// not possible to find with heights[i], we can stop here as not possile to find further
			break;
		}
	} else {
		res = min(res, heights[end] - heights[i]);
		
		// binary searching right most start
		auto iStart = i + 1;
		auto iEnd = end;
		while (iStart < iEnd) {
			int mid = iStart + (iEnd - iStart + 1) / 2;
			if (canReachAllHouses(t, houseCount, heights[mid], heights[end])) {
				iStart = mid;
				i = iStart;
				res = min(res, heights[end] - heights[iStart]);
			} else {
				iEnd = mid - 1;
			}
		}
	}
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

	clock_t begin = clock();
        auto res = solve(test);
	clock_t end = clock();
        cout << res << " : " << double(end - begin) / CLOCKS_PER_SEC << " sec" << endl;
        out << res << endl;
    }

    in.close();
    out.close();
    return 0;
}

