// P2303 SDOi2012]Longge的问题
// https://www.luogu.org/problem/P2303

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define int long long

int euler(int n) {
  int res = n;
  for (int i = 2ll; i * i <= n; ++i) {
    if (n % i == 0ll) {
      res = res / i * (i - 1ll);
      while (n % i == 0ll) {
        n /= i;
      }
    }
  }

  if (n > 1ll) {
    res = res / n * (n - 1);
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  int ans = 0ll;
  int sqn = sqrt(n);
  for (int i = 1ll; i <= sqn; i++) {
    if (n % i == 0) {
      int a = i;
      int b = n / i;
      ans += (a * euler(n / a));
      if (a * a != n) ans += (b * euler(n / b));
    }
  }
  cout << ans << endl;
  return 0;
}