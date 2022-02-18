#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
    ifstream in("testp1.txt");
    ofstream out("resp1.txt");
    int T;
    in >> T;
    for(int i = 0; i < T; i++){
        int n;
        in >> n;
        char x;
        vector<char> ans_ch;
        vector<int> ans_int;
        for(int i = 0; i < n; i++){
            in >> x;
            if(int(x) >= 97 && int(x) <= 122){
                ans_ch.push_back(char(int(x) - 32));
            }
            else if (int(x) >= 65 && int(x) <= 90){
                ans_ch.push_back(x);
            }
            else{
                int x_int = int(x) - 48;
                bool pr = true;
                for(int j = 0; j < ans_int.size(); j++){
                    if(int(x) - 48 != ans_int[j]){
                        pr = true;
                    }
                    else {
                        pr = false;
                        break;
                    }
                }

                if(pr){ans_int.push_back(x_int);}
            }
        }
        sort(ans_int.begin(), ans_int.end());
        for(int i = 0; i < ans_int.size(); i++){
            if(ans_int[i] != 0){
                int tmp = ans_int[0];
                ans_int[0] = ans_int[i];
                ans_int[i] = tmp;
                break;
            }
        }
        for(int i = 0; i < ans_ch.size(); i++){
            out << ans_ch[i];
        }
        out << endl;
        for(int i = 0; i < ans_int.size(); i++){
            out << ans_int[i];
        }
        out << endl;
    }
    in.close();
    out.close();
}
