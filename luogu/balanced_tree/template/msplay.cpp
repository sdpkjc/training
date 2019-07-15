#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

namespace splaytree {

const int MAX_N = 200005;
int ch[MAX_N][2], par[MAX_N];
int val[MAX_N];
int cnt[MAX_N];
int size[MAX_N];
int ncnt, root;
inline void init() {
  memset(ch, 0, sizeof(ch));
  memset(par, 0, sizeof(par));
  memset(val, 0, sizeof(val));
  memset(cnt, 0, sizeof(cnt));
  memset(size, 0, sizeof(size));
  ncnt = root = 0;
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
}  // namespace splaytree

int main() {
  int n;
  cin >> n;

  //   splaytree::init();
  splaytree::insert(0x3f3f3f3f);
  splaytree::insert(0xcfcfcfcf);

  while (n--) {
    int opt, x;
    cin >> opt >> x;
    if (opt == 1) {
      splaytree::insert(x);
    } else if (opt == 2) {
      splaytree::remove(x);
    } else if (opt == 3) {
      cout << splaytree::rank(x) << endl;
    } else if (opt == 4) {
      cout << splaytree::val[splaytree::kth(x + 1)] << endl;
    } else if (opt == 5) {
      cout << splaytree::val[splaytree::pre(x)] << endl;
    } else if (opt == 6) {
      cout << splaytree::val[splaytree::suc(x)] << endl;
    }
  }
  return 0;
}