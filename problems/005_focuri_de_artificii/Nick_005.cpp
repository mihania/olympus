#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, in_n;
    cin >> n;
    vector<int> h;
    vector<int> a;
    vector<int> b;
    int in_h, in_a, in_b;
    for(int i = 0; i < n; i++){
        cin >> in_h;
        h.push_back(in_h);
        cin >> in_a;
        a.push_back(in_a);
        cin >> in_b;
        b.push_back(in_b);
    }
    int x = 1;
    int max_x = 0;
    for(int i = 1; i < n; i++){
        if((h[i] >= a[i  - 1]) && (h[i] <= b[i - 1])){
                x++;
        }
        else {
            if(max_x <= x){
                max_x = x;
            }
            x = 0;
        }
    }
    cout << max_x;
}
