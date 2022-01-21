#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    ifstream in("test.txt");
    ofstream out("res.txt");
    int T;
    in >> T;
    cout << T;
    for(int i = 0; i < T; i++){
        int n, in_n;
        in >> n;
        vector<int> h;
        vector<int> a;
        vector<int> b;
        int in_h, in_a, in_b;
        for(int i = 0; i < n; i++){
            in >> in_h;
            h.push_back(in_h);
            in >> in_a;
            a.push_back(in_a);
            in >> in_b;
            b.push_back(in_b);
        }
        vector<int> dp (n, 1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if((a[j] <= h[i]) && (h[i] <= b[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        out << i + 1 << ". " << ans << endl;
    }
    in.close();
    out.close();
}
