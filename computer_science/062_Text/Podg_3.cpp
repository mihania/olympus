#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    ifstream in("testp3.txt");
    ofstream out("resp3.txt");
    vector<string> all_words;
    while(!in.eof()){
        string str;
        in >> str;
        if(str.size() != 0){
            all_words.push_back(str);
        }
    }
    vector<int> dp(all_words.size(), 1);
    vector<vector<string>> res_words;
    int ans_ind = 0;
    int max_s = 0;
    for(int i = 1; i < all_words.size(); i++) {
        for(int j = 0; j < i; j++){
            int s = all_words[j].size();
            if (dp[i] < dp[j] + 1 && all_words[j][s-1] == all_words[i][0]){
                dp[i] = dp[j] + 1;
                res_words[i].push_back(all_words[j]);
            }
        }
        ans = max(ans, dp[i]);
    }

    for(int i = 0; i < dp.size(); i++){
        if(ans = dp.size()){
            ans_ind = i;
        }
    }

    out << all_words.size() << endl;
    out << all_words.size() - ans<< endl;

    for(int j = 0; j < res_words[ans_ind].size(); j++){
        out << res_words[ans_ind][j] << endl;
    }
    in.close();
    out.close();
}
