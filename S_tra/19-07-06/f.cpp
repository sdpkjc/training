#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);
  int x, y, n, xx, yy, rr;
  scanf("%d%d%d", &x, &y, &n);
  int top = -1, but = 1001, lef = 1001, rig = -1;
  while (n--) {
    scanf("%d%d%d", &xx, &yy, &rr);
    top = max(top, yy + rr);
    but = min(but, yy - rr);
    lef = min(lef, xx - rr);
    rig = max(rig, xx + rr);
  }
  printf("%d", x * y - (top - but) * (rig - lef));
  return 0;
}
