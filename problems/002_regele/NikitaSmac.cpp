#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
    int n, s, gos, sum, sum1, anssum;
    bool answer;
    cin >> n >> s;
    vector<int> a;
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i = 0; i < n; i++){
        cin >> gos;
        a.push_back(gos);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        int s = ans.size();
        for(int j = 0; j < s; j++){
            vector<int> temp = ans[j];
            temp.push_back(a[i]);
            ans.push_back(temp);
        }
    }
    sum = 0;
    anssum = 0;
    for(int i = 1; i < ans.size();i++){
        for(int j = 0; j<ans[i].size();j++){
            sum += ans[i][j];
        }
        if(sum > s){
            sum1 = ans[i - 1][0];
            for(int j = 1; j<ans[i-1].size() - 1;j++){
                if(ans[i -1][j] > sum1){
                    answer = true;
                    sum += ans[i-1][j];
                }
                else {answer = false;i -=2;}
            }
            if (answer){
                for(int j = 0; j <ans[i -1].size();j++){
                    cout<<ans[i-1][j]<<endl;
                    anssum += ans[i-1][j];
                }
                cout << ans[i - 1].size()<< " "<< s - anssum;
                break;
            }
        }
        sum = 0;
        }
}