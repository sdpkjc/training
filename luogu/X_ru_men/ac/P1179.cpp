// P1179 数字统计
// https://www.luogu.org/problem/P1179

#include <iostream>
using namespace std;

int f(int n) {
  int re = 0;
  while (n) {
    if (n % 10 == 2) re++;
    n /= 10;
  }
  return re;
}

int main() {
  int L, R;
  cin >> L >> R;
  int ans = 0;
  for (int i = L; i <= R; i++) {
    ans += f(i);
  }
  cout << ans << endl;
  return 0;
}