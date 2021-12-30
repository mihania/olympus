#include <iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;
int main(){
    int n, number;
    cin >> n;
    vector<int> test;
    for(int i = 0; i < n; i++){
        cin >> number;
        test.push_back(number);
    }
    for(int i = 0; i < n; i++){
        string str = to_string(test[i]);
        int k = str.size() - 1;
        for(int j = 0; j < n / 2; j++){
            while(str[j] != str[k]){
                test[i] += pow(10, j);
                str = to_string(test[i]);
            }
            k--;
        }
    }
    for(int i = 0; i < n; i++){
        cout << test[i] << " ";
    }
}
