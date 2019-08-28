#include <algorithm>
#include <cmath>
#include <cstdio>
// #include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL qp(LL a, LL b) {
  LL ans;
  for (ans = 1; b; b >>= 1, a = a * a % MOD) {
    if (b & 1) ans = ans * a % MOD;
  }
  return ans;
}
LL r[500005], s[500005], x[500005], a[500005];
LL dp[500005];
LL Scan() {
  LL res = 0ll;
  char ch = getchar();
  if (ch >= '0' && ch <= '9') res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10ll + (ch - '0');
  return res;
}

int main() {
  LL T;
  T = Scan();
  while (T--) {
    LL n, q;
    n = Scan();
    q = Scan();

    for (int i = 1; i <= n; i++) {
      r[i] = Scan();
      s[i] = Scan();
      x[i] = Scan();
      a[i] = Scan();
    }
    dp[1] = 0;
    for (int i = 2; i <= n + 1; i++) {
      LL cg = r[i - 1], Ecg = a[i - 1];
      LL sb = s[i - 1] - r[i - 1],
         Esb = (dp[i - 1] - dp[x[i - 1]] + MOD + Ecg) % MOD;

      dp[i] = (dp[i - 1] + (cg * Ecg % MOD + sb * Esb % MOD) % MOD *
                               qp(r[i - 1], MOD - 2) % MOD) %
              MOD;
    }
    for (int i = 0; i < q; i++) {
      LL a, b;
      a = Scan();
      b = Scan();
      printf("%lld\n", (dp[b] - dp[a] + MOD) % MOD);
    }
  }

  return 0;
}