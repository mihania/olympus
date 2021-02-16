#include <iostream>
using namespace std;
int main() {
  long long p = 1000;
  long long q = 1000;;
  int N = 1000;
  for (int i = 1; i <= N; i++) {
    long long tmp = q;
    q = p;
    p = tmp + p;
  }
  cout << p + q;
  return 0;
}
