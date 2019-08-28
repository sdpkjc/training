// P1548 棋盘问题
// https://www.luogu.org/problem/P1548

#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cnt = (n - i + 1) * (m - j + 1);
      if (i == j) {
        ans1 += cnt;
      } else {
        ans2 += cnt;
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}