// P1615 西游记公司
// https://www.luogu.org/problem/P1615

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  long long a, b, c;
  long long x, y, z;
  scanf("%lld:%lld:%lld", &a, &b, &c);
  scanf("%lld:%lld:%lld", &x, &y, &z);
  long long n;
  scanf("%lld", &n);
  long long ans = (x - a) * 3600 + (y - b) * 60 + (z - c);
  ans *= n;
  cout << ans << endl;
  return 0;
}