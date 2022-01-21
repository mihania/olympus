#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <fstream>
using namespace std;
int main(){
    ifstream in("test_02.txt");
    ofstream out("res.txt");
    in >> T;
    for(int i = 0; i < T; i++){
        int n, s, gos, res_cit, sum, dif, cit;
        in >> n >> s;
        vector<int> test;
        vector<int> result;
        dif = s;
        for(int i = 0; i < n; i++){
            in >> gos;
            test.push_back(gos);
        }
        sort(test.begin(), test.end());
        int tmp = pow(2, n);
        for(int x = 0; x < tmp; x++){
            vector<int> subset;
            int k = x;
            int i = 0;
            while(k > 0){
                if(k % 2 == 1){
                    subset.push_back(test[i]);
                    }
                k /= 2;
                i++;
            }
            sum = 0;
            for(int i = 0; i < subset.size(); i++){
                if(subset[i] > sum){
                    sum += subset[i];
                }
                else {
                    sum = 0;
                    break;
                }
            }
            if((sum <= s) && (s-sum < dif)){
                dif = s - sum;
                result = subset;
            }
        }
            out << result.size() << " " << dif << endl;
            for(int i = 0; i < result.size(); i++){
                out << result[i] << " ";
            }
        in.close();
        out.close();
    }
}
