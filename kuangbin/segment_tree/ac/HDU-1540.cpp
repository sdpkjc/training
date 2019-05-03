// HDU-1540 Tunnel Warfare
// https://vjudge.net/problem/HDU-1540

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 50010;
struct node {
  int l, r;
  int ll, rr, ml;
} st[MAX_N << 2];

void build(int p, int l, int r) {
  st[p].l = l;
  st[p].r = r;
  st[p].ll = st[p].rr = st[p].ml = r - l + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}

void up(int p) {
  st[p].ll = st[p << 1].ll;
  st[p].rr = st[p << 1 | 1].rr;
  st[p].ml = max(max(st[p << 1].ml, st[p << 1 | 1].ml),
                 st[p << 1].rr + st[p << 1 | 1].ll);
  if (st[p << 1].ll == st[p << 1].r - st[p << 1].l + 1)
    st[p].ll += st[p << 1 | 1].ll;
  if (st[p << 1 | 1].rr == st[p << 1 | 1].r - st[p << 1 | 1].l + 1)
    st[p].rr += st[p << 1].rr;
}

void modify(int p, int x, int c) {
  if (st[p].l == st[p].r) {
    st[p].ll = st[p].rr = st[p].ml = c;
    return;
  }
  int mid = (st[p].l + st[p].r) / 2;
  if (x <= mid) {
    modify(p * 2, x, c);
  } else {
    modify(p * 2 + 1, x, c);
  }
  up(p);
}

int query(int p, int x) {
  if (st[p].l == st[p].r || st[p].ml == 0 ||
      st[p].ml == (st[p].r - st[p].l + 1)) {
    return st[p].ml;
  }
  int mid = (st[p].l + st[p].r) / 2, res = 0;
  if (x <= mid) {
    if (x >= st[p << 1].r - st[p << 1].rr + 1) {
      return query(p << 1, x) + query(p << 1 | 1, mid + 1);
    } else {
      return query(p << 1, x);
    }
  } else {
    if (x <= st[p << 1 | 1].l + st[p << 1 | 1].ll - 1) {
      return query(p << 1 | 1, x) + query(p << 1, mid);
    } else {
      return query(p << 1 | 1, x);
    }
  }
  return res;
}

void init() { memset(st, 0, sizeof(st)); }
int stk[50005];
int top;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    top = 0;
    while (q--) {
      char com;
      int x;
      scanf(" %c", &com);
      if (com == 'D') {
        scanf("%d", &x);
        modify(1, x, 0);
        stk[top++] = x;
      } else if (com == 'Q') {
        scanf("%d", &x);
        printf("%d\n", query(1, x));
      } else if (com == 'R') {
        modify(1, stk[--top], 1);
      }
    }
  }

  return 0;
}

// 最大连续区间\*