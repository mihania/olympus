#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    ifstream in("test_004.txt");
    ofstream out("res.txt");
    int T;
    in >> T;
    for (int i = 0; i < T; i++){
        int n, in_number;
        in >> n;
        vector<int> numbers;
        for(int i = 0; i < n; i++){
            in >> in_number;
            numbers.push_back(in_number);
        }
        int x = 0;
        int m, m_ind; // minimun and min index
        for(int i = 0; i < n; i++){
            m = numbers[i];
            for(int j = i + 1; j < n; j++){
                if(m > numbers[j]){
                    m = numbers[j];
                    m_ind = j;
                }
            }
            if(m < numbers[i]){
                int tmp = numbers[i];
                numbers[i] = numbers[m_ind];
                numbers[m_ind] = tmp;
                x++;
            }
        }
        for(int i = 0; i < n; i++){
            out << numbers[i] << " ";
        }
        out << endl;
        out << x << endl;
        }
    in.close();
    out.close();
}
