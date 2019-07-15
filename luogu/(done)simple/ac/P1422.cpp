#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double a, ans = 0;
  cin >> a;
  if (a > 0) {
    ans += (0.4463 * (min(a, 150.0)));
    a -= (min(a, 150.0));
  }
  if (a > 0) {
    ans += (0.4663 * (min(a, 250.0)));
    a -= (min(a, 250.0));
  }
  if (a > 0) {
    ans += (0.5663 * a);
    a -= (a);
  }
  printf("%.1lf\n", ans);
  return 0;
}