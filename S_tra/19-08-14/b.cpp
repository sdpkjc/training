#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6 + 10;
// ll aa[MAX_N];
// ll bb[MAX_N];
struct xx {
  ll a, b;
  bool operator<(const xx& x) const {
    if (a != x.a) return a > x.a;
    return b > x.b;
  }
} X[MAX_N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    queue<pair<ll, ll> > Q;

    for (int i = 0; i < n; i++) {
      cin >> X[i].a >> X[i].b;
    }
    sort(X, X + n);
    for (int i = 0; i < n; i++) {
      if (X[i].b > 0ll) Q.push(make_pair(X[i].b, i));
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll x = X[i].a;
      ll q = -1;
      while (true) {
        if (Q.empty()) break;
        if (x <= 0ll) break;
        ll b = Q.front().first;
        ll ii = Q.front().second;
        if (q == ii) {
          break;
        }
        q = ii;
        Q.pop();

        if (ii == i) {
          Q.push(make_pair(b, ii));
        } else {
          ll tmp = min(x, b);
          x -= tmp;
          b -= tmp;
          ans += tmp;
          if (b > 0ll) {
            Q.push(make_pair(b, ii));
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}