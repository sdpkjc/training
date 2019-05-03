// HDU-4027 Can you answer these queries?
// https://vjudge.net/problem/HDU-4027

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int MAX_N = 100010;
int s[4 * MAX_N];
void up(int p) { s[p] = s[p * 2] + s[p * 2 + 1]; }

void build(int p, int l, int r) {
  if (l == r) {
    scanf("%lld", &s[p]);
    return;
  }
  int mid = (l + r) >> 1;

  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);

  up(p);
}

void modify(int p, int l, int r, int x, int y, int c) {
  if (l == r) {
    s[p] = (int)sqrt(s[p]);
    return;
  }
  if (x > r || y < l) return;                         //不在区间内
  if (x <= l && y >= r && s[p] == r - l + 1) return;  // 等于 1

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
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res += query(p * 2, l, mid, x, y);
  }
  if (y > mid) {
    res += query(p * 2 + 1, mid + 1, r, x, y);
  }
  return res;
}

void init() { memset(s, 0, sizeof(s)); }

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, CNT = 1;
  while (~scanf("%lld", &n)) {
    printf("Case #%lld:\n", CNT++);
    init();
    build(1, 1, n);
    int q;
    scanf("%lld", &q);
    while (q--) {
      int d, x, y;
      scanf("%lld%lld%lld", &d, &x, &y);
      int l = min(x, y);
      int r = max(x, y);
      if (d == 0) {
        modify(1, 1, n, l, r, -1);
      } else {
        printf("%lld\n", query(1, 1, n, l, r));
      }
    }
    printf("\n");
  }

  return 0;
}

// 区间开平方，优化做完还要输入输出挂，build()快速建树。