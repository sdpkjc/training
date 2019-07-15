// P3380 【模板】二逼平衡树（树套树）
// https://www.luogu.org/problemnew/show/P3380

#include <algorithm>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]

const int MAXN = 5e4;
const int INF = 0x7fffffff;

struct node {
  int child[2], size, value, key;
} arr[MAXN * 25];

int tot;

inline void push_up(int index) {
  arr[index].size = arr[ls(index)].size + arr[rs(index)].size + 1;
}

void split(int root, int &x, int &y, int value) {
  if (!root) {
    x = y = 0;
    return;
  }
  if (arr[root].value <= value) {
    x = root;
    split(rs(root), rs(x), y, value);
  } else {
    y = root;
    split(ls(root), x, ls(y), value);
  }
  push_up(root);
}

void merge(int &root, int x, int y) {
  if (!x || !y) {
    root = x + y;
    return;
  }
  if (arr[x].key < arr[y].key) {
    root = x;
    merge(rs(root), rs(x), y);
  } else {
    root = y;
    merge(ls(root), x, ls(y));
  }
  push_up(root);
}

inline void insert(int &root, int value) {
  int x = 0, y = 0, z = ++tot;
  arr[z].value = value, arr[z].size = 1, arr[z].key = rand();
  split(root, x, y, value);
  merge(x, x, z);
  merge(root, x, y);
}

inline void erase(int &root, int value) {
  int x = 0, y = 0, z = 0;
  split(root, x, y, value);
  split(x, x, z, value - 1);
  merge(z, ls(z), rs(z));
  merge(x, x, z);
  merge(root, x, y);
}
inline int kth(int root, int k) {
  while (arr[ls(root)].size + 1 != k) {
    if (arr[ls(root)].size >= k)
      root = ls(root);
    else
      k -= (arr[ls(root)].size + 1), root = rs(root);
  }
  return arr[root].value;
}

inline int atrank(int &root, int value) {
  int x = 0, y = 0;
  split(root, x, y, value - 1);
  int res = arr[x].size;
  merge(root, x, y);
  return res;
}

inline int pre(int &root, int value) {
  int x = 0, y = 0;
  split(root, x, y, value - 1);
  int res = -INF;
  if (arr[x].size) res = kth(x, arr[x].size);
  merge(root, x, y);
  return res;
}
inline int suc(int &root, int value) {
  int x = 0, y = 0;
  split(root, x, y, value);
  int res = INF;
  if (arr[y].size) res = kth(y, 1);
  merge(root, x, y);
  return res;
}

// seg

int T[4 * MAXN];

void add(int p, int l, int r, int x, int c) {
  insert(T[p], c);
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) {
    add(p * 2, l, mid, x, c);
  } else {
    add(p * 2 + 1, mid + 1, r, x, c);
  }
}

void del(int p, int l, int r, int x, int c) {
  erase(T[p], c);
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) {
    del(p * 2, l, mid, x, c);
  } else {
    del(p * 2 + 1, mid + 1, r, x, c);
  }
}

int query_rank(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    return atrank(T[p], c);
  }
  int mid = (l + r) / 2, res = 0;
  if (x <= mid) {
    res += query_rank(p * 2, l, mid, x, y, c);
  }
  if (y > mid) {
    res += query_rank(p * 2 + 1, mid + 1, r, x, y, c);
  }
  return res;
}
int query_pre(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    return pre(T[p], c);
  }
  int mid = (l + r) / 2, res = -INF;
  if (x <= mid) {
    res = max(res, query_pre(p * 2, l, mid, x, y, c));
  }
  if (y > mid) {
    res = max(res, query_pre(p * 2 + 1, mid + 1, r, x, y, c));
  }
  return res;
}
int query_suc(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    return suc(T[p], c);
  }
  int mid = (l + r) / 2, res = INF;
  if (x <= mid) {
    res = min(res, query_suc(p * 2, l, mid, x, y, c));
  }
  if (y > mid) {
    res = min(res, query_suc(p * 2 + 1, mid + 1, r, x, y, c));
  }
  return res;
}

int read() {
  char c = getchar();
  int x = 0, flag = 1;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') flag = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return flag * x;
}

int n, opt, x, root = 0;
int a[MAXN];
int main() {
  srand(19260817);
  int n, m;
  // cin >> n >> m;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    int t;
    // cin >> t;
    t = read();
    add(1, 1, n, i, t);
    a[i] = t;
  }
  for (int i = 0; i < m; i++) {
    int opt;
    int l, r, x, pos;
    // cin >> opt;
    opt = read();

    if (opt == 1) {
      // cin >> l >> r >> x;
      l = read();
      r = read();
      x = read();

      printf("%d\n", query_rank(1, 1, n, l, r, x) + 1);
      //   cout << query_rank(1, 1, n, l, r, x) + 1 << endl;
    } else if (opt == 2) {
      // cin >> l >> r >> x;
      l = read();
      r = read();
      x = read();

      int lt = 0, rt = 1e8;
      while (lt < rt) {
        int mid = (rt + lt + 1) / 2;
        if (query_rank(1, 1, n, l, r, mid) < x) {
          lt = mid;
        } else {
          rt = mid - 1;
        }
      }
      // cout << rt << endl;
      printf("%d\n", rt);
    } else if (opt == 3) {
      // cin >> pos >> x;
      pos = read();
      x = read();

      del(1, 1, n, pos, a[pos]);
      a[pos] = x;
      add(1, 1, n, pos, a[pos]);
    } else if (opt == 4) {
      // cin >> l >> r >> x;
      l = read();
      r = read();
      x = read();

      // cout << query_pre(1, 1, n, l, r, x) << endl;
      printf("%d\n", query_pre(1, 1, n, l, r, x));
    } else if (opt == 5) {
      // cin >> l >> r >> x;
      l = read();
      r = read();
      x = read();

      // cout << query_suc(1, 1, n, l, r, x) << endl;
      printf("%d\n", query_suc(1, 1, n, l, r, x));
    }
  }
  return 0;
}