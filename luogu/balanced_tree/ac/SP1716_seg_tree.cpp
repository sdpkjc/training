// SP1716 GSS3 - Can you answer these queries III
// https://www.luogu.org/problemnew/show/SP1716

#include <string.h>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAX_N = 100010;
struct node {
  int s, pl, pr, res;
} seg[4 * MAX_N];
void up(int p) {
  seg[p].s = seg[p * 2].s + seg[p * 2 + 1].s;
  seg[p].pl = max(seg[p * 2].pl, seg[p * 2].s + seg[p * 2 + 1].pl);
  seg[p].pr = max(seg[p * 2 + 1].pr, seg[p * 2 + 1].s + seg[p * 2].pr);
  seg[p].res = max(seg[p * 2].pr + seg[p * 2 + 1].pl,
                   max(seg[p * 2].res, seg[p * 2 + 1].res));
}

void modify(int p, int l, int r, int x, int c) {
  if (l == r) {
    seg[p].s = seg[p].pl = seg[p].pr = seg[p].res = c;
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

node query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return seg[p];
  }
  int mid = (l + r) / 2;
  if (y <= mid) {
    return query(p * 2, l, mid, x, y);
  }
  if (x > mid) {
    return query(p * 2 + 1, mid + 1, r, x, y);
  }
  node ln = query(p * 2, l, mid, x, mid),
       rn = query(p * 2 + 1, mid + 1, r, mid + 1, y);
  node res;
  res.s = ln.s + rn.s;
  res.pl = max(ln.pl, ln.s + rn.pl);
  res.pr = max(rn.pr, rn.s + ln.pr);
  res.res = max(ln.pr + rn.pl, max(ln.res, rn.res));
  return res;
}

void init() { memset(seg, 0, sizeof(seg)); }

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int d;
    scanf("%d", &d);
    modify(1, 1, n, i, d);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int d, x, y;
    scanf("%d%d%d", &d, &x, &y);
    if (d == 0) {
      modify(1, 1, n, x, y);
    } else {
      printf("%d\n", query(1, 1, n, x, y).res);
    }
  }

  return 0;
}