#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;

long long MOD = 1e9 + 7;
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

LL arr[100005];
int dp[1005][1005];

int main() {
  int T;
  cin >> T;
  for (int i = 1; i < 1e4; i++) {
    arr[i] = qp(i, MOD - 2);
  }
  for (int t = 0; t < T; t++) {
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
      cout << 1 << endl;
      continue;
    }
    long long a = n - 1;
    long long b = n + m - 2;

    long long x = 1;
    for (long long i = b; i >= a; i--) {
      x = (x * i) % MOD;
    }
    for (long long i = a; i >= 1; i--) {
      x = x * arr[i] % MOD;
    }
    cout << x * m % MOD << endl;
    a = a;
    b = b - 1;
    long long xx = 1;
    for (long long i = b; i >= a; i--) {
      xx = (xx * i) % MOD;
    }
    for (long long i = a; i >= 1; i--) {
      xx = xx * arr[i] % MOD;
    }
    cout << x << " " << xx << endl;
    // cout << x - xx << endl;
  }
  return 0;
}