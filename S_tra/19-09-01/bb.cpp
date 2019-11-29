#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

ll ph(ll x) {
  ll res = x, a = x;
  for (ll i = 2; i * i <= x; i++) {
    if (a % i == 0) {
      res = res / i * (i - 1);
      while (a % i == 0) a /= i;
    }
  }
  if (a > 1) res = res / a * (a - 1);
  return res;
}
ll quick_pow(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
ll a, b;

ll f(ll p) {
  if (p == 1) return 0;
  ll k = ph(p);
  //   ll k = b;
  return quick_pow(a, f(k) + k, p);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld\n", f(p));
  }
  return 0;
}
