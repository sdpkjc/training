// POJ-3264 Balanced Lineup
// https://vjudge.net/problem/POJ-3264

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 200010;
int s[4 * MAX_N];
int si[4 * MAX_N];
void up(int p) {
  s[p] = max(s[p * 2], s[p * 2 + 1]);
  si[p] = min(si[p * 2], si[p * 2 + 1]);
}

void modify(int p, int l, int r, int x, int c) {
  if (l == r) {
    s[p] = c;
    si[p] = c;
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

int queryx(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p];
  }
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res = max(res, queryx(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = max(res, queryx(p * 2 + 1, mid + 1, r, x, y));
  }
  return res;
}
int queryi(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return si[p];
  }
  int mid = (l + r) / 2, res = 0x3f3f3f3f;
  if (x <= mid) {
    res = min(res, queryi(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = min(res, queryi(p * 2 + 1, mid + 1, r, x, y));
  }
  return res;
}
void init() {
  memset(s, 0, sizeof(s));
  memset(si, 0, sizeof(si));
}

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
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", queryx(1, 1, n, a, b) - queryi(1, 1, n, a, b));
    }
  }

  return 0;
}

// 维护区间最大值和最小值