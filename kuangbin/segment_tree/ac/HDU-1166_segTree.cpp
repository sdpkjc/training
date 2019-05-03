// HDU-1166 敌兵布阵
// https://vjudge.net/problem/HDU-1166

#include <string.h>
#include <cstdio>
using namespace std;
const int MAX_N = 50005;
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

int main() {
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    init();
    printf("Case %d:\n", Case);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int d;
      scanf("%d", &d);
      modify(1, 1, n, i, i, d);
    }
    char str[50];
    while (true) {
      scanf("%s", str);
      if (str[0] == 'E') break;
      int a, b;
      scanf(" %d%d", &a, &b);
      if (str[0] == 'A') {
        modify(1, 1, n, a, a, b);
      } else if (str[0] == 'S') {
        modify(1, 1, n, a, a, -b);
      } else if (str[0] == 'Q') {
        printf("%d\n", query(1, 1, n, a, b));
      }
    }
  }

  return 0;
}

// 水