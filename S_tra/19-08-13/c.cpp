#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

ll Gcd(ll a, ll b) { return !b ? a : Gcd(b, a % b); }

int main() {
  int n;
  scanf("%d", &n);
  ll a, b;
  cin >> a;
  while (--n) {
    cin >> b;
    a = Gcd(a, b);
  }
  int ans = 0;
  for (ll i = 1; i * i <= a; i++) {
    if (i * i == a) {
      ans++;
      break;
    }
    if (a % i == 0) {
      ans += 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}