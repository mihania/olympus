#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int G;
    cin >> G;
    int price[] = {1, 5, 10, 25, 50};
    int num = G / 5;
    int M = num * price[4];
    if (num >= 1) {
        M = M + price[num % 5];
    }
    
    cout << M << endl;
    return 0;
}
