#include <string.h>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 100010;
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
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp == 1) {
        modify(1, 1, n, 1, i - 1, 1);
        modify(1, 1, n, i, i, i - 1);
      }
    }
    int cnt = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      int x = query(1, 1, n, i, i);
      if (x % 2 == 1) {
        cnt++;
      }
      if (x == 0) {
        flag = false;
        break;
      }
    }
    if (cnt > 2 || cnt == 1 || !flag) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }

  return 0;
}