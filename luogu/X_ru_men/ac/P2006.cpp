// P2006 赵神牛的游戏
// https://www.luogu.org/problem/P2006

#include <iostream>
using namespace std;

int main() {
  int k, m, n;
  cin >> k >> m >> n;
  bool flag = false;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if ((a != 0 && (k / a) * b >= n) || (a == 0 && b != 0)) {
      if (flag) cout << " ";
      cout << i;
      flag = true;
    }
  }
  if (!flag) cout << -1;
  cout << endl;
  return 0;
}