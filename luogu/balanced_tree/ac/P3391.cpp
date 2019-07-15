// P3391 【模板】文艺平衡树（Splay）
// https://www.luogu.org/problemnew/show/P3391

#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;

namespace splaytree {

const int MAX_N = 200005;
int ch[MAX_N][2], par[MAX_N];
int val[MAX_N];
int cnt[MAX_N];
int size[MAX_N];
int ncnt, root;

int rev[MAX_N];  // *

void pushdown(int x) {  // *
  if (rev[x]) {
    swap(ch[x][0], ch[x][1]);
    rev[ch[x][0]] ^= 1;
    rev[ch[x][1]] ^= 1;
    rev[x] = 0;
  }
}

inline int chk(int x) { return ch[par[x]][1] == x; }
inline void pushup(int x) {
  size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x];
}
void rotate(int x) {
  int y = par[x], z = par[y], k = chk(x), w = ch[x][k ^ 1];
  ch[y][k] = w;
  par[w] = y;
  ch[z][chk(y)] = x;
  par[x] = z;
  ch[x][k ^ 1] = y;
  par[y] = x;
  pushup(y);
  pushup(x);
}
void splay(int x, int goal = 0) {
  while (par[x] != goal) {
    int y = par[x], z = par[y];
    if (z != goal) {
      if (chk(x) == chk(y))
        rotate(y);
      else
        rotate(x);
    }
    rotate(x);
  }
  if (!goal) root = x;
}

void insert(int x) {
  int cur = root, p = 0;

  while (cur && val[cur] != x) {
    p = cur;
    cur = ch[cur][x > val[cur]];
  }
  if (cur) {
    cnt[cur]++;
  } else {
    cur = ++ncnt;
    if (p) ch[p][x > val[p]] = cur;
    ch[cur][0] = ch[cur][1] = 0;
    par[cur] = p;
    val[cur] = x;
    cnt[cur] = size[cur] = 1;
  }
  splay(cur);
}
void find(int x) {
  if (!root) return;
  int cur = root;
  while (ch[cur][x > val[cur]] && x != val[cur]) {
    cur = ch[cur][x > val[cur]];
  }
  splay(cur);
}
int kth(int k) {
  int cur = root;
  while (true) {
    pushdown(cur);  // *
    if (ch[cur][0] && k <= size[ch[cur][0]]) {
      cur = ch[cur][0];
    } else if (k > size[ch[cur][0]] + cnt[cur]) {
      k -= size[ch[cur][0]] + cnt[cur];
      cur = ch[cur][1];
    } else {
      return cur;
    }
  }
}

int pre(int x) {
  find(x);
  if (val[root] < x) return root;
  int cur = ch[root][0];
  while (ch[cur][1]) {
    cur = ch[cur][1];
  }
  return cur;
}
int suc(int x) {
  find(x);
  if (val[root] > x) return root;
  int cur = ch[root][1];
  while (ch[cur][0]) {
    cur = ch[cur][0];
  }
  return cur;
}
void remove(int x) {
  int last = pre(x), next = suc(x);
  splay(last);
  splay(next, last);
  int del = ch[next][0];
  if (cnt[del] > 1) {
    cnt[del]--;
    splay(del);
  } else {
    ch[next][0] = 0;
  }
}

int rank(int x) {
  find(x);
  return size[ch[root][0]];
}

void reverse(int l, int r) {  // *
  int x = kth(l), y = kth(r + 2);
  splay(x);
  splay(y, x);
  rev[ch[y][0]] ^= 1;
}
void output(int x) {  // *
  pushdown(x);
  if (ch[x][0]) output(ch[x][0]);
  if (val[x] && val[x] <= n) cout << val[x] << " ";
  if (ch[x][1]) output(ch[x][1]);
}
}  // namespace splaytree

int main() {
  cin >> n >> m;

  for (int i = 0; i <= n + 1; i++) {
    splaytree::insert(i);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    splaytree::reverse(l, r);
  }
  splaytree::output(splaytree::root);
  cout << endl;
  return 0;
}