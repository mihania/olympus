#include <iostream>
#include <string>
using namespace std;

int main() {
  int a;
  cin >> a;
  int d = 2;
  string res = "";
  while (a > 0) {
    res = to_string(a % d) + res;
    a /= d;
    d++;
  }

  printf("%s\n", res.c_str());
  return 0;
}
