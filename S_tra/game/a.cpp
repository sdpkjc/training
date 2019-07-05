#include <limits.h>
#include <iostream>
using namespace std;

// #define int long long
const int MAX_N = 100010;
struct node {
  int sum, max, min, col;
} s[4 * MAX_N];
void up(int p) {
  s[p].sum = s[p * 2].sum + s[p * 2 + 1].sum;
  s[p].max = max(s[p * 2].max, s[p * 2 + 1].max);
  s[p].min = min(s[p * 2].min, s[p * 2 + 1].min);
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
    s[p * 2 + 1].min += s[p].col;
    s[p * 2].min += s[p].col;
    s[p].col = 0;
  }
}

void modify(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    s[p].sum += (r - l + 1) * c;
    s[p].col += c;
    s[p].max += c;
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

int queryMax(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return s[p].max;
  }
  down(p, l, r);
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res = max(res, queryMax(p * 2, l, mid, x, y));
  }
  if (y > mid) {
    res = max(res, queryMax(p * 2 + 1, mid + 1, r, x, y));
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

signed main() {
  int n, m;
  cin >> n >> m;

  modify(1, 1, n, 1, n, 0);

  while (m--) {
    char ca;
    int x, y, c;
    cin >> ca;
    if (ca == 'Q') {
      cin >> x >> y;
      cout << querySum(1, 1, n, x, y) << endl;
    } else if (ca == 'C') {
      cin >> x >> y >> c;
      modify(1, 1, n, x, y, c);
    } else if (ca == 'X') {
      cin >> x >> y;
      modify(1, 1, n, x, y, queryMax(1, 1, n, x, y));
    } else if (ca == 'N') {
      cin >> x >> y;
      modify(1, 1, n, x, y, -queryMin(1, 1, n, x, y));
    }
  }

  return 0;
}