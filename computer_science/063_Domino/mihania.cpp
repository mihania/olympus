#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
 * O(2^N)
 * 1. Find all possible subsets
 * 2. For each subset build a histogram v->d that maps for each value number of dominos on which it appears.
 * 3. If no more than  two values in histogram have odd count - the chain can be formed, otherwise no.
 */
int solve(vector<vector<int>>& v) {
    int res = 0;
    for (long i = 0; i < pow(2, v.size()); i++) {
        vector<int> hist(7, 0);
        int count = 0;
        int pos = 0;
        for (auto k = i; k > 0; k /= 2) {
            if (k % 2 == 1) {
                auto left = v[pos][0];
                auto right = v[pos][1];
                if (left == right) {
                    hist[left]++;
                } else {
                    hist[left]++;
                    hist[right]++;
                }

                count++;
            }

            pos++;
        }

        int odd = 0;
        for (int c : hist) {
            if (c % 2 == 1) {
                odd++;
            }
        }

        // odd == 2 needed for 2 doubles case (3,3), (4,4)
        if (odd < 2 || (odd == 2 && count != 2)) {
            res = max(res, count);
        }
    }

    return res;
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
