#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
int main(){
    ifstream in("test_56.txt");
    ofstream out("res.txt");
    in >> T;
    for(int i = 0; i < T; i++){
        int n, number;
        in >> n;
        vector<int> test;
        for(int i = 0; i < n; i++){
            in >> number;
            test.push_back(number);
        }
        for(int i = 0; i < n; i++){
            string str = to_string(test[i]);
            int k = str.size() - 1;
            for(int j = 0; j < str.size() / 2; j++){
                while(str[j] != str[k]){
                    test[i] += pow(10, j);
                    str = to_string(test[i]);
                }
                k--;
            }
        }
        for(int i = 0; i < n; i++){
            out << test[i] << " ";
        }
        in.close();
        out.close();
    }
}
