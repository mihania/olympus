#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> x;
    int n;
    cin >> n;
    int count;
    for(int i = 0; i < n; i++){
        cin >> count;
        x.push_back(count);
    }
    for(int i = 0; i < n; i++){
        cout << x[i] + 1 << endl;d
    }
}
