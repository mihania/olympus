#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main (){
	ifstream in("REGE.IN");
	ofstream out("REGE.OUT");
    int n, s, gos;
    bool answer;
    in >> n >> s;
    vector<int> a;
    vector<vector<int>> subsets;
    subsets.push_back({});
    for(int i = 0; i < n; i++){
        in >> gos;
        a.push_back(gos);
    }
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
    for(int i = subsets.size() - 1; i > 0; i--){
        for(int j = 0; j <subsets[i].size();j++){
            sum += subsets[i][j];}
        if (sum <= s){
            int sum1 = 0;
            for(int j = 0; j < subsets[i].size() - 1;j++){
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
            out << subsets[i - 1].size() << " " << s - sum << endl;
            for(int j = 0; j < subsets[i].size(); j++){
                out << subsets[i][j] << endl;
            }
			break;
        }
        sum = 0;
    }
	
	in.close();
	out.close();
}