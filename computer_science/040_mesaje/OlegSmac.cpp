#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>
#include<cmath>

using namespace std;

int main() {
    ifstream in("test.in");
    ofstream out("res.txt");
    vector<int> v;
    int len;
    in >> len;
    for (int i = 0; i < len; i++) {
        int num;
        in >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < len; i++) {
        cout << v[i] << " ";
    }

    in.close();
    out.close();
}
