#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
ll a[100105];
ll b[100105];
ll ans[200105];
ll MAX = 1e8;

struct x {
 public:
  ll a, b;
  x() {}
  x(ll a, ll b) : a(a), b(b) {}

  bool operator<(const x& ot) const {
    if (b != ot.b) return b < ot.b;
    return a < ot.a;
  }
  ll sumx() const { return a + b; }
};
struct y {
 public:
  ll a, b;
  y() {}
  y(ll a, ll b) : a(a), b(b) {}
  bool operator<(const y& ot) const {
    if (a != ot.a) return a + b < ot.a + ot.b;
    return a < ot.a;
  }
  ll sumx() const { return a + b; }
};
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    multiset<x> S;
    multiset<y> Sum;
    for (int i = 0; i < n * 2 + 10; i++) {
      ans[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld", &a[i], &b[i]);
      S.insert(x(a[i], b[i]));
      Sum.insert(y(a[i], b[i]));
      ans[2 * n] += (a[i] + b[i]);
    }
    int plan = -1;
    x re(MAX, MAX);
    for (int i = n * 2 - 1; i >= 0; i--) {
      ll tmpb, tmpa;
      tmpb = ans[i + 2] - Sum.begin()->sumx();
      y tmp = *Sum.begin();
      y ty(re.a, re.b);
      S.erase(re);
      Sum.erase(ty);
      if (re.b != MAX) {
        S.insert(x(re.b, MAX));
        Sum.insert(y(re.b, MAX));
      }
      tmpa = ans[i + 1] - S.begin()->b;

      if (tmpa >= tmpb) {
        re = x(MAX, MAX);
        ans[i] = tmpa;
      } else {
        if (re.b != MAX) {
          S.erase(x(re.b, MAX));
          Sum.erase(y(re.b, MAX));
        }
        S.insert(re);
        Sum.insert(ty);
        re = x(tmp.a, tmp.b);
        ans[i] = tmpb;
      }
    }
    for (int i = 1; i <= n * 2; i++) {
      if (i != 1) putchar(' ');
      printf("%lld", ans[i]);
    }
    putchar('\n');
  }
  return 0;
}