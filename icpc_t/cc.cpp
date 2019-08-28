#include <limits.h>
#include <string.h>
#include <iostream>
using namespace std;

// #define int long long
const int MAX_N = 100010;
struct node {
  long long sum, min, col;
} s[4 * MAX_N];

void up(long long p) {
  s[p].sum = s[p * 2ll].sum + s[p * 2ll + 1ll].sum;
  s[p].min = min(s[p * 2ll].min, s[p * 2ll + 1ll].min);
}

void down(int p, long long l, long long r) {
  long long mid = (l + r) / 2ll;
  if (s[p].col) {
    s[p * 2ll].sum += s[p].col * (mid - l + 1ll);
    s[p * 2ll + 1ll].sum += s[p].col * (r - mid);
    s[p * 2ll].col += s[p].col;
    s[p * 2ll + 1ll].col += s[p].col;
    s[p * 2ll + 1ll].min += s[p].col;
    s[p * 2ll].min += s[p].col;
    s[p].col = 0ll;
  }
}

void modify(long long p, long long l, long long r, long long x, long long y,
            long long c) {
  if (x <= l && r <= y) {
    s[p].sum += (r - l + 1ll) * c;
    s[p].col += c;
    s[p].min += c;
    return;
  }
  down(p, l, r);
  long long mid = (l + r) / 2ll;
  if (x <= mid) {
    modify(p * 2ll, l, mid, x, y, c);
  }
  if (y > mid) {
    modify(p * 2ll + 1ll, mid + 1ll, r, x, y, c);
  }
  up(p);
}

long long queryMin(long long p, long long l, long long r, long long x,
                   long long y) {
  if (x <= l && r <= y) {
    return s[p].min;
  }
  down(p, l, r);
  long long mid = (l + r) / 2;
  long long res = 0x3f3f3f3f3f3f3f3f;
  if (x <= mid) {
    res = min(res, queryMin(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = min(res, queryMin(p * 2 + 1, mid + 1, r, x, y));
  }
  return res;
}

signed main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
      long long t;
      cin >> t;
      modify(1, 1, n, i, i, t);
    }
    long long ans = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
      long long x = i, y = i + k - 1;
      long long tt = queryMin(1, 1, n, x, y);
      modify(1, 1, n, x, y, -tt);
      ans += tt;
    }
    cout << ans << endl;
  }

  return 0;
}