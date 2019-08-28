// P1590 失踪的7
// https://www.luogu.org/problem/P1590

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int T;
  cin >> T;
  while (T--) {
    ll p = 1, ans = 0, x, t;
    cin >> x;
    while (x) {
      t = x % 10;
      if (t >= 7) t--;
      ans += p * t;
      p *= 9;
      x /= 10;
    }
    cout << ans << endl;
  }
}

// 10 进制转 9 进制