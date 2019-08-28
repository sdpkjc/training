#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define int long long

const int MAX_N = 100100, M = 55;
int rt[22 * MAX_N];
int a[22 * MAX_N];
int cntn;
struct node {
  int l, r, cnt;
} s[22 * MAX_N];
vector<int> V, ans;
void modify(int pre, int &now, int p, int l, int r) {
  now = ++cntn;
  s[now].l = s[pre].l;
  s[now].r = s[pre].r;
  s[now].cnt = s[pre].cnt + 1;
  if (l == r) return;
  int mid = (l + r) / 2;
  if (p <= mid) {
    modify(s[pre].l, s[now].l, p, l, mid);
  } else {
    modify(s[pre].r, s[now].r, p, mid + 1, r);
  }
}

void query(int l, int r, int x, int y) {
  if (s[r].cnt - s[l].cnt == 0 || ans.size() == M) return;
  if (x == y) {
    for (int i = 0; i < s[r].cnt - s[l].cnt; i++) {
      if (ans.size() < M)
        ans.push_back(V[x - 1]);
      else
        return;
    }
    return;
  }
  int mid = (x + y) / 2;
  query(s[l].r, s[r].r, mid + 1, y);
  query(s[l].l, s[r].l, x, mid);
}
int n, q;
int F(int x) { return lower_bound(V.begin(), V.end(), x) - V.begin() + 1; }
signed main() {
  while (~scanf("%lld%lld", &n, &q)) {
    cntn = 0;
    V.clear();
    for (int i = 1; i < n + 1; ++i) {
      scanf("%lld", &a[i]);
      V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for (int i = 1; i < n + 1; ++i) {
      int x = F(a[i]);
      rt[i] = 0;
      modify(rt[i - 1], rt[i], x, 1, (int)V.size());
    }
    while (q--) {
      int x, y;
      scanf("%lld%lld", &x, &y);
      ans.clear();
      query(rt[x - 1], rt[y], 1, (int)V.size());
      int res = -1;
      for (int i = 2; i < ans.size(); i++) {
        int a = ans[i - 2];
        int b = ans[i - 1];
        int c = ans[i];
        if (a < b + c && b < a + c && c < a + b) {
          res = a + b + c;
          break;
        }
      }
      printf("%lld\n", res);
    }
  }

  return 0;
}
