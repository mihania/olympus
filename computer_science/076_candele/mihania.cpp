#include <iostream>
using namespace std;
int main() {
  int N = 3;
  int k = 3;
  for (int i = 1; i <= N; i++) {
    long long tmp = q;
    q = p;
    p = tmp + p;
  }

  cout << p + q;
  return 0;
}
