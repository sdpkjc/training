// HDU-1754 I Hate It
// https://vjudge.net/problem/HDU-1754

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 200010;
int s[4 * MAX_N];
void up(int p) { s[p] = max(s[p * 2], s[p * 2 + 1]); }

void modify(int p, int l, int r, int x, int c) {
  if (l == r) {
    s[p] = c;
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

int query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p];
  }
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res = max(res, query(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = max(res, query(p * 2 + 1, mid + 1, r, x, y));
  }
  return res;
}

void init() { memset(s, 0, sizeof(s)); }

int main() {
  int n, q;
  while (~scanf("%d%d", &n, &q)) {
    init();
    for (int i = 1; i <= n; i++) {
      int d;
      scanf("%d", &d);
      modify(1, 1, n, i, d);
    }
    while (q--) {
      char c;
      int a, b;
      scanf(" %c%d%d", &c, &a, &b);
      if (c == 'Q') {
        printf("%d\n", query(1, 1, n, a, b));
      } else if (c == 'U') {
        int as = query(1, 1, n, a, a);
        modify(1, 1, n, a, b);
      }
    }
  }

  return 0;
}

// 单点更新，区间最大值，三个函数都要改