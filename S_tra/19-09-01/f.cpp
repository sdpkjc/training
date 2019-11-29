#include <limits.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int MAX_N = 100010;
struct node {
  int sum, max, col;
} s[4 * MAX_N];
void up(int p) {
  s[p].sum = s[p * 2].sum + s[p * 2 + 1].sum;
  s[p].max = max(s[p * 2].max, s[p * 2 + 1].max);
}

void down(int p, int l, int r) {
  int mid = (l + r) / 2;
  if (s[p].col) {
    s[p * 2].sum += s[p].col * (mid - l + 1);
    s[p * 2 + 1].sum += s[p].col * (r - mid);
    s[p * 2].col += s[p].col;
    s[p * 2].max += s[p].col;
    s[p * 2 + 1].col += s[p].col;
    s[p * 2 + 1].max += s[p].col;
    s[p].col = 0;
  }
}

void modify(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    s[p].sum += (r - l + 1) * c;
    s[p].col += c;
    s[p].max += c;
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

int queryMax(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p].max;
  }
  down(p, l, r);
  int mid = (l + r) / 2, res = INT_MIN;
  if (x <= mid) {
    res = max(res, queryMax(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = max(res, queryMax(p * 2 + 1, mid + 1, r, x, y));
  }
  return res;
}

pair<int, int> Parr[MAX_N];
int ans[MAX_N];

signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);

    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) {
      cin >> Parr[i].first;
      Parr[i].second = i + 1;
    }
    sort(Parr, Parr + n);
    for (int i = 0; i < n; i++) {
      int l = max(1, Parr[i].second - k);
      int r = min(n, Parr[i].second + k);
      int x = queryMax(1, 1, n, l, r);
      if (x == 0) {
        ans[i + 1] = 1;
      } else {
        ans[i + 1] = ans[x] + 1;
      }
      modify(1, 1, n, Parr[i].second, Parr[i].second, i + 1);
    }
    for (int i = 1; i <= n; i++) {
      if (i != 1) putchar(' ');
      printf("%d", ans[i]);
    }
    putchar('\n');
  }
  return 0;
}