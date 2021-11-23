#include <iostream>
#include <algorithm>
using namespace std;
int main (){
    int n, s, x, m, rem_soldats; //x - это сумма значений завоёванных стран(их солдат)
    cin >> n >> s;
    int *a = new int[n];
    m = 0;
    int *answer = new int[m];
    rem_soldats = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    x = a[n-1];
    for(int i = n-1; i > 0; i--){
        if(s >= x){
                answer[m] = a[i];
                rem_soldats = s-x;
                x += a[i-1];
                m++;
        }
        else x = x - a[i] + a[i - 1];
    }
    cout << m << " "<< rem_soldats << endl;
    for (int i = m - 1; i >= 0; i--){
        cout << answer[i] << endl;
    }
}
