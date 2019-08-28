// P1482 Cantor表（升级版）
// https://www.luogu.org/problem/P1482

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  int a, b, x, y;
  scanf("%d/%d", &a, &b);
  scanf("%d/%d", &x, &y);

  int aa = a * x;
  int bb = b * y;
  int gg = gcd(aa, bb);
  cout << bb / gg << " " << aa / gg << endl;
  return 0;
}