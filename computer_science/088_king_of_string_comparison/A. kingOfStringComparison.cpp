#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main() {
    long long n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    long long res = 0;
    long long theSame = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            theSame++;
        }
        else if (s[i] < t[i]) {
            res += n - i;
            if (theSame > 0) {
                res += (n - i) * theSame;
                theSame = 0;
            }
        }
        else {
            theSame = 0;
        }
    }

    cout << res << endl;
}
