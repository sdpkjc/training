#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 3001000;

struct node {
  int sum, min, col;
} s[4 * MAX_N];

void up(int p) {
  s[p].sum = s[p * 2].sum + s[p * 2 + 1].sum;
  s[p].min = min(s[p * 2].min, s[p * 2 + 1].min);
}

void down(int p, int l, int r) {
  int mid = (l + r) / 2;
  if (s[p].col) {
    s[p * 2].sum += s[p].col * (mid - l + 1);
    s[p * 2 + 1].sum += s[p].col * (r - mid);
    s[p * 2].col += s[p].col;
    s[p * 2].min += s[p].col;
    s[p * 2 + 1].col += s[p].col;
    s[p * 2 + 1].min += s[p].col;
    s[p].col = 0;
  }
}

void modify(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    s[p].sum += (r - l + 1) * c;
    s[p].col += c;
    s[p].min += c;
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
int querySum(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p].sum;
  }
  down(p, l, r);
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res += querySum(p * 2, l, mid, x, y);
  }
  if (y > mid) {
    res += querySum(p * 2 + 1, mid + 1, r, x, y);
  }
  return res;
}
int queryMin(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p].min;
  }
  down(p, l, r);
  int mid = (l + r) / 2, res = INT_MAX;
  if (x <= mid) {
    res = min(res, queryMin(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = min(res, queryMin(p * 2 + 1, mid + 1, r, x, y));
  }
  return res;
}

int Vy[MAX_N];
int kx;
int yh(int y) { return lower_bound(Vy, Vy + kx, y) - Vy + 1; }

vector<pair<int, int> > Qa;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int vys = 0;
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    Qa.push_back(make_pair(a, b));
    Vy[vys++] = b;
    Vy[vys++] = b + 1;
  }

  sort(Vy, Vy + vys);
  kx = unique(Vy, Vy + vys) - Vy + 1;
  for (int i = 1; i <= kx; i++) {
    modify(1, 1, kx, i, i, i);
  }

  for (int i = 0; i < q; i++) {
    int a = Qa[i].first;
    int b = Qa[i].second;
    int tp = yh(Qa[i].second);
    if (a == 1) {
      int tmp = querySum(1, 1, kx, tp, tp);
      modify(1, 1, kx, tp, tp, INT_MAX - tmp);
    } else {
      int x = queryMin(1, 1, kx, tp, kx);
      if (x == INT_MAX) {
        printf("%d", -1);
      } else {
        printf("%d", Vy[x - 1]);
      }
      putchar('\n');
    }
  }

  return 0;
}