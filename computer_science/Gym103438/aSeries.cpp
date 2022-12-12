#include<iostream>
#include<math.h>

using namespace std;

int main() {
    long long N;
    cin >> N;
    long long a[N + 1];
    long long b[N + 1];

    for (int i = 0; i <= N; i++) {
        long long elem;
        cin >> elem;
        a[i] = elem;
    }
    for (int i = 0; i <= N; i++) {
        long long elem;
        cin >> elem;
        b[i] = elem;
    }

    long long cuts = 0;

    for (long long i = N; i >= 1; i--) {
        if (b[i] > a[i]) {
            long long need = (b[i] - a[i]) / 2 + (b[i] - a[i]) % 2;
            a[i - 1] -= need;
            cuts += need;
        }
    }

    if (a[0] < b[0]) {
        cout << -1 << endl;
    }
    else {
        cout << cuts << endl;
    }

    return 0;
}
