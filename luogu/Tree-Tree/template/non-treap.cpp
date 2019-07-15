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

const int MAXN = 100005;

struct node {
  int child[2], size, value, key;
} arr[MAXN];

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
  int res = arr[x].size + 1;
  merge(root, x, y);
  return res;
}

inline int pre(int &root, int value) {
  int x = 0, y = 0;
  split(root, x, y, value - 1);
  int res = kth(x, arr[x].size);
  merge(root, x, y);
  return res;
}
inline int suc(int &root, int value) {
  int x = 0, y = 0;
  split(root, x, y, value);
  int res = kth(y, 1);
  merge(root, x, y);
  return res;
}
int n, opt, x, root = 0;
int main() {
  srand(19260817);
  cin >> n;
  while (n--) {
    cin >> opt >> x;
    if (opt == 1) {
      insert(root, x);
    } else if (opt == 2) {
      erase(root, x);
    } else if (opt == 3) {
      printf("%d\n", atrank(root, x));
    } else if (opt == 4) {
      printf("%d\n", kth(root, x));
    } else if (opt == 5) {
      printf("%d\n", pre(root, x));
    } else if (opt == 6) {
      printf("%d\n", suc(root, x));
    }
  }
  return 0;
}