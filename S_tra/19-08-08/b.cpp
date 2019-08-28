#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const ll MAXN = 1e5 + 5;

struct Tree {
  ll high;  //高度
  ll cost;  //消费
  ll numb;  //数量
  bool operator<(const Tree& b) const { return high < b.high; }
};

Tree tree[MAXN];
ll sum[205];

ll que(ll nx) {
  ll re = 0;
  if (nx <= 0) return 0;
  for (int i = 1; i <= 200 && nx > 0; i++) {
    re += (min(sum[i], nx) * i);
    nx -= min(sum[i], nx);
  }
  return re;
}

int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < 205; i++) sum[i] = 0;
    ll allsum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld%lld", &tree[i].high, &tree[i].cost, &tree[i].numb);
      allsum += (tree[i].cost * tree[i].numb);
    }
    sort(tree, tree + n);
    ll precost = 0, prenum = 0, ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0, j; i < n; i = j) {
      ll selfn = 0;
      for (j = i; j < n && tree[i].high == tree[j].high; j++) {
        precost += (tree[j].cost * tree[j].numb);
        prenum += (tree[j].numb);
        selfn += (tree[j].numb);
      }
      ll ne = allsum - precost;
      ll pr = que((prenum - selfn) - selfn + 1);
      ll tans = ne + pr;

      ans = min(tans, ans);
      for (j = i; j < n && tree[i].high == tree[j].high; j++) {
        sum[tree[j].cost] += tree[j].numb;
      }
    }
    printf("%lld\n", ans);
  }
}