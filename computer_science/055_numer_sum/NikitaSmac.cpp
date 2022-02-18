#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
int main(){
    ifstream in("test_55.txt");
    ofstream out("res_55.txt");
    int T;
    in >> T;
    for(int i = 0; i < T; i++){
        int a, number;
        in >> a;
        vector<int> test;
        for(int i = 0; i < a; i++){
            in >> number;
            test.push_back(number);
        }
        int sum, j, x, st;
        sum = 0;
        j = 0;
        vector <int> answer;
        for(int i = 0; i < a; i++){
            x = test[i];
            while(x > 9){
                sum += x % 10;
                x = x / 10;
                j++;
            }
            st = pow(10, j);
            if ((test[i] / st) == sum){
                answer.push_back(test[i]);
            }
            j = 0;
            sum = 0;
        }
        sort(answer.begin(), answer.end());
        for(int i = answer.size() - 1; i >= 0; i--){
            out << answer[i] << " " << endl;
        }
    }
    in.close();
    out.close();
}
