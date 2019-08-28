// P1420 最长连号
// https://www.luogu.org/problem/P1420

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int q = -10;
  int ans = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == q + 1) {
      cnt++;
    } else {
      cnt = 1;
    }
    ans = max(ans, cnt);
    q = a;
  }
  cout << ans << endl;
  return 0;
}