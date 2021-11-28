#include <iostream>
using namespace std;
int main(){
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        while(a > 9){
            a = a % 10 + a / 10;
            if (a == 7) cout << "norocos" << endl;
            if (a == 8) cout << "vorbaret" << endl;
            if (a == 9) cout << "intelegent" << endl;
            if (a <= 6) cout << "obisnuit" << endl;
        }
    }
}
