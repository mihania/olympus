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
    int x, max_x;
    max_x = 0;
    for(int i = 0; i < n; i++){
        x = 0;
        for(int j = 0; j < n; j++){
            if((h[i] >= a[j]) && (h[i] <= b[j]) && (j != i)){
                x++;
            }
        }
        cout << x << " " << i << endl;
        if(max_x <= x){
            max_x = x;
        }
    }
    cout << max_x;
}
