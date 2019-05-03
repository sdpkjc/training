// POJ-3468 A Simple Problem with Integers
// https://vjudge.net/problem/POJ-3468

#include <string.h>
#include <cstdio>
using namespace std;
#define int long long
const int MAX_N = 100005;
int s[4 * MAX_N], col[4 * MAX_N];
void up(int p) { s[p] = s[p * 2] + s[p * 2 + 1]; }

void down(int p, int l, int r) {
  if (col[p]) {
    int mid = (l + r) / 2;
    s[p * 2] += col[p] * (mid - l + 1);
    s[p * 2 + 1] += col[p] * (r - mid);
    col[p * 2] += col[p];
    col[p * 2 + 1] += col[p];
    col[p] = 0;
  }
}
void modify(int p, int l, int r, int x, int c) {
  if (l == r) {
    s[p] += c;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) {
    modify(p * 2, l, mid, x, c);
  } else {
    modify(p * 2 + 1, mid + 1, r, x, c);
  }
  up(p);
}
void modify(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    s[p] += (r - l + 1) * c;
    col[p] += c;
    return;
  }
  down(p, l, r);
  int mid = (l + r) / 2;
  if (x <= mid) {
    modify(p * 2, l, mid, x, y, c);
  }
  if (y > mid) {
    modify(p * 2 + 1, mid + 1, r, x, y, c);
  }
  up(p);
}

int query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p];
  }
  down(p, l, r);
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res += query(p * 2, l, mid, x, y);
  }
  if (y > mid) {
    res += query(p * 2 + 1, mid + 1, r, x, y);
  }
  return res;
}

void init() {
  memset(s, 0, sizeof(s));
  memset(col, 0, sizeof(col));
}

signed main() {
  int n, q;
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    int d;
    scanf("%lld", &d);
    modify(1, 1, n, i, i, d);
  }
  while (q--) {
    int x, y, c;
    char d;
    scanf(" %c%lld%lld", &d, &x, &y);
    if (d == 'C') {
      scanf("%lld", &c);
      modify(1, 1, n, x, y, c);
    } else if (d == 'Q') {
      printf("%lld\n", query(1, 1, n, x, y));
    }
  }

  return 0;
}