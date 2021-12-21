#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
    int n, s, gos;
    bool answer;
    cin >> n >> s;
    vector<int> a;
    vector<vector<int>> subsets;
    //subsets.push_back({});
    cout << "n = " << n << " s = " << s;
    for(int i = 0; i < n; i++){
        cin >> gos;
        a.push_back(gos);
    }
    cout << "by here";
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        int s = subsets.size();
        for(int j = 0; j < s; j++){
            vector<int> temp = subsets[j];
            temp.push_back(a[i]);
            subsets.push_back(temp);
        }
    }
    int sum = 0;
    for(int i = subsets[i].size() - 1; i > 0;i--){
        for(int j = 0; j<subsets[i].size();j++){
            sum += subsets[i][j];}
        if (sum <= s){
            int sum1 = 0;
            for(int j = 0; j <subsets[i].size() - 1;j++){
                    if (subsets[i][j] > sum1){
                        answer = true;
                        sum1 += subsets[i][j];
                    }
                    else {
                        answer = false;
                    }
            }
        }
        if (answer){
            cout << subsets[i - 1].size()<< " "<< s-sum;
            for(int j = 0; j < subsets[i].size(); j++){
                cout<< subsets[i][j]<<endl;
            }
        }
        sum = 0;
    }
}
