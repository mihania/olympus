#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, in_number;
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        cin >> in_number;
        numbers.push_back(in_number);
    }
    int temp, x;
    x = 0;
    temp = 0;
    for(int i = 0; i <= n / 2; i++){
        for(int j = n - 1; j >= n / 2; j--){
            if(numbers[i] > numbers[j]) {
                temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
                x++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << x;
}
