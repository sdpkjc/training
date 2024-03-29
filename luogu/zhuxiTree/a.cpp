// P3834 【模板】可持久化线段树 1（主席树）
// https://www.luogu.org/problem/P3834

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 200010;
const int M = MAXN * 30;
int n, q, m, tot;
int a[MAXN], t[MAXN];
int T[MAXN], lson[M], rson[M], c[M];
void Init_hash() {
  for (int i = 1; i <= n; i++) t[i] = a[i];
  sort(t + 1, t + 1 + n);
  m = unique(t + 1, t + 1 + n) - t - 1;
}
int build(int l, int r) {
  int root = tot++;
  c[root] = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    lson[root] = build(l, mid);
    rson[root] = build(mid + 1, r);
  }
  return root;
}
int mhash(int x) { return lower_bound(t + 1, t + 1 + m, x) - t; }
int update(int root, int pos, int val) {
  int newroot = tot++, tmp = newroot;

  c[newroot] = c[root] + val;

  int l = 1, r = m;

  while (l < r) {
    int mid = (l + r) >> 1;

    if (pos <= mid) {
      lson[newroot] = tot++;
      rson[newroot] = rson[root];
      newroot = lson[newroot];
      root = lson[root];
      r = mid;

    }

    else {
      rson[newroot] = tot++;
      lson[newroot] = lson[root];
      newroot = rson[newroot];
      root = rson[root];
      l = mid + 1;
    }
    c[newroot] = c[root] + val;
  }
  return tmp;
}
int query(int left_root, int right_root, int k) {
  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (c[lson[left_root]] - c[lson[right_root]] >= k) {
      r = mid;
      left_root = lson[left_root];
      right_root = lson[right_root];
    } else {
      l = mid + 1;
      k -= c[lson[left_root]] - c[lson[right_root]];
      left_root = rson[left_root];
      right_root = rson[right_root];
    }
  }
  return l;
}
int main() {
  while (scanf("%d%d", &n, &q) == 2) {
    tot = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    Init_hash();
    T[n + 1] = build(1, m);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      T[i + 1] = update(T[i + 1], a[i], 1);
      ans += query(T[i + 1], T[i + 1], k);
    }

    for (int i = n; i; i--) {
      int pos = mhash(a[i]);
      T[i] = update(T[i + 1], pos, 1);
    }
    while (q--) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      printf("%d\n", t[query(T[l], T[r + 1], k)]);
    }
  }
  return 0;
}