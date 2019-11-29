#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
ll euler(ll x) {
  ll ans = x;
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans -= ans / i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) ans -= ans / x;
  return ans;
}
ll quick(ll x, ll y, ll mo) {
  ll ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mo;
    y >>= 1;
    x = x * x % mo;
  }
  return ans;
}
char s[1000006];

int main() {
  ll x, y;
  while (scanf("%lld %s %lld", &x, s, &y) > 0) {
    ll q, re = 0;
    q = euler(y);
    ll len = strlen(s);
    for (int i = 0; i < len; i++) {
      re = (re * 10 + s[i] - '0') % q;
    }
    re += q;
    re = quick(x, re, y);
    cout << re << endl;
  }
}
