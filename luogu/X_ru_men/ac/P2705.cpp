// P2705 小球
// https://www.luogu.org/problem/P2705

#include <iostream>
using namespace std;

int main() {
  int r, b, c, d, e;
  cin >> r >> b >> c >> d >> e;
  int ans = r * c + b * d;
  if (2 * e > c + d) {
    int xmin = min(r, b);
    ans += xmin * (2 * e - c - d);
  }
  cout << ans << endl;
  return 0;
}