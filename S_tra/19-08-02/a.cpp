#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;
const int k = 350;
int n, m;
vector<int> G[MAX_N];
long long kv[1000];
int dep[MAX_N] = {0};
int sqk[1000][MAX_N];
long long af[MAX_N];
vector<int> dfsl;
pair<int, int> pa[MAX_N];
void dfs(int x, int d) {
  dep[x] = d;
  dfsl.push_back(x);
  int l = dfsl.size() - 1;
  for (int i = 0; i < G[x].size(); i++) {
    if (dep[G[x][i]] == 0) {
      dfs(G[x][i], d + 1);
    }
  }
  int r = dfsl.size() - 1;
  pa[x] = make_pair(l, r);
}

void add(long long de, long long c) {
  for (int i = 0; i <= n / k; i++) {
    kv[i] += (sqk[i][de] * c);
  }
  af[de] += c;
}

long long que(int a) {
  long long re = 0;
  int l = pa[a].first, r = pa[a].second;

  int lk = l / k, rk = r / k;
  if (lk == rk) {
    for (int i = l; i <= r; i++) {
      re += af[dep[dfsl[i]]];
    }
  } else {
    for (int i = lk + 1; i <= rk - 1; i++) {
      re += kv[i];
    }
    for (int i = l; i < (lk + 1) * k; i++) {
      re += af[dep[dfsl[i]]];
    }
    for (int i = rk * k; i <= r; i++) {
      re += af[dep[dfsl[i]]];
    }
  }
  return re;
}

signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    dep[i]--;
  }
  for (int i = 0; i < n; i++) {
    int kp = i / k;
    sqk[kp][dep[dfsl[i]]]++;
  }

  while (m--) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      long long d, x;
      scanf("%lld%lld", &d, &x);
      add(d, x);
    } else if (cmd == 2) {
      int a;
      scanf("%d", &a);
      printf("%lld\n", que(a));
    }
  }
  return 0;
}