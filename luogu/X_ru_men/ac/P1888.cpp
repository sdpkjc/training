// P1888 三角函数
// https://www.luogu.org/problem/P1888

#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int xmax = -1, xmin = 0x3f3f3f3f;
  xmax = max(xmax, a);
  xmax = max(xmax, b);
  xmax = max(xmax, c);
  xmin = min(xmin, a);
  xmin = min(xmin, b);
  xmin = min(xmin, c);
  cout << xmin / gcd(xmax, xmin) << "/" << xmax / gcd(xmax, xmin) << endl;

  return 0;
}