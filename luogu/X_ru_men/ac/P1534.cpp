// P1534 不高兴的津津（升级版）
// https://www.luogu.org/problem/P1534

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int q = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int x = q + a + b - 8;
    ans += x;
    q = x;
  }
  cout << ans << endl;
  return 0;
}