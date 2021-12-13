#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
    int n, s, gos;
    cin >> n >> s;
    vector<int> a;
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i = 0; i < n; i++){
        cin >> gos;
        a.push_back(gos);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        int s = ans.size();
        for(int j = 0; j < s; j++){
            vector<int> temp = ans[j];
            temp.push_back(a[i]);
            ans.push_back(temp);
        }
    }
    int sum;
    vector<vector<int>> x;
    sort(ans.begin(), ans.end());
    for(int i = ans.size() - 1; i >= 0; i--){
        for (int j = 0; j < ans[i].size(); j++){
            sum += ans[i][j];
        }
        if(sum <= s){
            x.push_back(ans[i]);
        }
        sum = 0;
    }
    sort(x.begin(), x.end());
    for(int i = 0; i< x.size() - 1; i++){
        for(int j = 0; j<x[i].size() - 2;j++){
            sum += x[i][j];
            if(x[i][j + 1] >= sum){
                cout<<x[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
