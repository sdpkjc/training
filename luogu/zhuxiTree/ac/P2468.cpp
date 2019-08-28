// P2468 [SDOI2010]粟粟的书架
// https://www.luogu.org/problem/P2468

#include <assert.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 500010;
const int M = MAXN * 30;

int n, q, m, tot;
int a[MAXN];
int T[MAXN], lson[M], rson[M], c[M], sm[M];

int build(int l, int r) {
  int root = tot++;
  c[root] = 0;
  sm[root] = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    lson[root] = build(l, mid);
    rson[root] = build(mid + 1, r);
  }
  return root;
}
int update(int root, int pos, int val) {
  int newroot = tot++, tmp = newroot;
  c[newroot] = c[root] + val;
  sm[newroot] = sm[root] + pos;

  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      lson[newroot] = tot++;
      rson[newroot] = rson[root];
      newroot = lson[newroot];
      root = lson[root];
      r = mid;
    } else {
      rson[newroot] = tot++;
      lson[newroot] = lson[root];
      newroot = rson[newroot];
      root = rson[root];
      l = mid + 1;
    }
    c[newroot] = c[root] + val;
    sm[newroot] = sm[root] + pos;
  }
  return tmp;
}
int query(int left_root, int right_root, int k) {
  int l = 1, r = m;
  int ans = 0;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (sm[rson[left_root]] - sm[rson[right_root]] < k) {
      k -= sm[rson[left_root]] - sm[rson[right_root]];
      ans += (c[rson[left_root]] - c[rson[right_root]]);
      left_root = lson[left_root];
      right_root = lson[right_root];
      r = mid;
    } else {
      left_root = rson[left_root];
      right_root = rson[right_root];
      l = mid + 1;
    }
  }
  ans += (k + l - 1) / l;

  return ans;
}

int num[205][205][1005];
int val[205][205][1005];
int aa[205][205];

int getval(int a1, int b1, int a2, int b2, int k) {
  return val[a2][b2][k] - val[a1 - 1][b2][k] + val[a1 - 1][b1 - 1][k] -
         val[a2][b1 - 1][k];
}

int getnum(int a1, int b1, int a2, int b2, int k) {
  return num[a2][b2][k] - num[a1 - 1][b2][k] + num[a1 - 1][b1 - 1][k] -
         num[a2][b1 - 1][k];
}
signed main() {
  int R, C, M;
  cin >> R >> C >> M;
  // assert(R == 1);
  if (R == 1) {
    n = C;
    tot = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    m = 1005;
    T[n + 1] = build(1, m);
    // cout << "S" << endl;
    for (int i = n; i; i--) {
      T[i] = update(T[i + 1], a[i], 1);
    }
    q = M;
    while (q--) {
      int a, b, l, r, k;
      cin >> a >> l >> b >> r >> k;
      if (sm[T[l]] - sm[T[r + 1]] >= k) {
        int x = query(T[l], T[r + 1], k);
        cout << x << endl;
      } else {
        cout << "Poor QLW" << endl;
      }
    }
  } else {
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        scanf("%d", &aa[i][j]);
      }
    }

    for (int k = 0; k < 1005; k++) {
      for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
          num[i][j][k] = num[i - 1][j][k] + num[i][j - 1][k] -
                         num[i - 1][j - 1][k] + (aa[i][j] >= k);
          val[i][j][k] = val[i - 1][j][k] + val[i][j - 1][k] -
                         val[i - 1][j - 1][k] + (aa[i][j] >= k) * aa[i][j];
        }
      }
    }
    q = M;
    while (q--) {
      int a1, b1, a2, b2, k;
      cin >> a1 >> b1 >> a2 >> b2 >> k;
      if (getval(a1, b1, a2, b2, 0) >= k) {
        int l = 1, r = 1005;
        while (l + 1 < r) {
          int mid = (l + r) >> 1;
          if (getval(a1, b1, a2, b2, mid) >= k) {
            l = mid;
          } else {
            r = mid;
          }
        }
        cout << getnum(a1, b1, a2, b2, l) - (getval(a1, b1, a2, b2, l) - k) / l
             << endl;
      } else {
        cout << "Poor QLW" << endl;
      }
    }
  }
  return 0;
}