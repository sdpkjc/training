#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 1e6;
const int MOD = 1e9 + 7;

LL qp(LL a, LL b) {
  LL ans;
  for (ans = 1; b; b >>= 1, a = a * a % MOD) {
    if (b & 1) ans = ans * a % MOD;
  }
  return ans;
}

LL el(LL n) {
  LL res = n;
  for (LL i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res = res / i * (i - 1);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    res = res / n * (n - 1);
  }
  return res;
}

void count(int n, int t) {
  long long ans = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      int a = i;
      int b = n / i;
      ans = (ans + el(n / a) % MOD * qp(t, a) % MOD) % MOD;
      if (a != b) {
        a = b;
        ans = (ans + el(n / a) % MOD * qp(t, a) % MOD) % MOD;
      }
    }
  }

  printf("%lld\n", ans * qp(n, 1e9 + 5) % MOD);
}

int main() {
  LL a, b;
  while (cin >> a >> b) {
    count(a, b);
  }
  return 0;
}