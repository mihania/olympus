#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main() {
    long long N;
    string s;
    cin >> N >> s;
    long long len = 2 * N;

    //vector<bool> visited (len, false);
    int cntA = 0, cntB = 0, cntC = 0;
    set<long long> a, b, c;

    for (long long i = 0; i < len; i++) {
        if (s[i] == 'A') {
            cntA++;
            a.insert(i);
        }
        if (s[i] == 'B') {
            cntB++;
            b.insert(i);
        }
        if (s[i] == 'C') {
            cntC++;
            c.insert(i);
        }
    }

    float X = (cntA + cntB - cntC) / 2;
    float Y = (cntA + cntC - cntB) / 2;
    float Z = (cntB + cntC - cntA) / 2;
    vector<pair<long long, long long>> res;

    if (X < 0 || Y < 0 || Z < 0 || X != round(X) || Y != round(Y) || Z != round(Z)) {
        cout << "NO" << endl;
        return 0;
    }
    /*
    x /= 2;
    y /= 2;
    z /= 2;
    */

    for (int i = 0; i < Z; i++) {
        auto idxB = b.begin();
        auto idxC = c.upper_bound(*idxB);

        if (idxC == c.end()) {
            cout << "NO" << endl;
            return 0;
        }

        //cout << "idxB = " << *idxB << " idxC = " << *idxC << endl;

        res.push_back({*idxB + 1, *idxC + 1});

        b.erase(*idxB);
        c.erase(*idxC);
    }

    for (int i = 0; i < X; i++) {
        auto idxB = b.begin();
        auto idxA = a.upper_bound(*idxB);

        if (idxA != a.begin()){
            idxA--;
        } else {
            cout << "NO" << endl;
            return 0;
        }

        //cout << "idxA = " << *idxA << " idxB = " << *idxB << endl;
        res.push_back({*idxA + 1, *idxB + 1});
        a.erase(*idxA);
        b.erase(*idxB);
    }

    for (int i = 0; i < Y; i++) {
        auto idxA = a.begin();
        auto idxC = c.upper_bound(*idxA);

        if (idxC == c.end()) {
            cout << "NO" << endl;
            return 0;
        }

        //cout << "idxA = " << *idxA << " idxC = " << *idxC << endl;
        res.push_back({*idxA + 1, *idxC + 1});
        a.erase(*idxA);
        c.erase(*idxC);
    }

    if (res.size() == N) {
        cout << "YES" << endl;
        for (long long i = 0; i < res.size(); i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }
        return 0;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
