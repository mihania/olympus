#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
int main(){
    ifstream in("tests.txt");
    ofstream out("res.txt");
    int T;
    in >> T;
    cout << "T = " << T;
    for(int i = 0; i < T; i++){
        int n;
        in >> n;
        vector<int> x;
        vector<int> y;
        int c_x, c_y;
        for(int i = 0; i < n; i++){
            in >> c_x;
            x.push_back(c_x);
            in >> c_y;
            y.push_back(c_y);
        }
        int r_x; // разница в расстоянии по х.
        int r_y; // разница в расстоянии по у.
        double pred_rast, max_rast;
        max_rast = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                r_x = abs(x[i] - x[j]);
                r_y = abs(y[i] - y[j]);
                pred_rast = sqrt((pow(r_x, 2) + pow(r_y, 2)));
                if(max_rast < pred_rast) {
                    max_rast = pred_rast;
                }
            }
        }
        out << max_rast<< endl;
    }
    in.close();
    out.close();
}
