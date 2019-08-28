#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;

ll a[MAXN][MAXN];
ll b[MAXN];
ll c[MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%lld", &a[i][j]);
        ans -= a[i][j];
      }
      c[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      scanf("%lld", &b[i]);
      ans += b[i];
    }
    for (int i = m; i >= 0; i--) {
      ll temp = ans;
      bool flag = false;
      ll mi = 0x3f3f3f3f3f3f3f3f;
      for (int j = 1; j <= n; j++) {
        c[j] += a[j][i];
        if (c[j] > 0) {
          ans += c[j];
          c[j] = 0;
          flag = true;
        }
        mi = min(mi, -c[j]);
      }
      if (!flag) ans -= mi;
      ans -= b[i];
      if (ans < temp) {
        ans = temp;
        // break;
      }
      cout << ans << endl;
    }
    printf("Case #%d: %lld\n", i, ans);
  }
}