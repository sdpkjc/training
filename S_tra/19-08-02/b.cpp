#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m, s, num[maxn], dep[maxn], fson[maxn], eson[maxn], qq[maxn];
int cnt, head[maxn], son[2 * maxn], nex[2 * maxn];
long long val[maxn], sonnum[maxn][320];
vector<int> G[maxn];

void add(int x, int y) {
  son[++cnt] = y;
  nex[cnt] = head[x];
  head[x] = cnt;
}

void dfs(int x, int f) {  // printf("%d %d\n", x, f);
  dep[x] = dep[f] + 1;
  G[dep[x]].push_back(x);
  num[dep[x]]++;
  fson[x] = ++cnt;
  for (int i = head[x]; i; i = nex[i]) {
    int u = son[i];
    if (u == f) continue;
    dfs(u, x);
  }
  eson[x] = cnt;
}

void dfs2(int x, int f) {
  if (qq[dep[x]]) {
    sonnum[x][qq[dep[x]]] += 1;
  }
  for (int i = head[x]; i; i = nex[i]) {
    int u = son[i];
    if (u == f) continue;
    dfs2(u, x);
    for (int j = 1; j <= cnt; j++) sonnum[x][j] += sonnum[u][j];
  }
}

long long sum[maxn];

int lowbit(int x) { return x & (-x); }

void change(int qq, long long val) {
  while (qq <= n) {
    sum[qq] += val;
    qq += lowbit(qq);
  }
}

long long query(int qq) {
  long long ans = 0;
  while (qq) {
    ans += sum[qq];
    qq -= lowbit(qq);
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  s = sqrt(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  cnt = 0;
  dfs(1, 0);
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (num[i] > s) {
      qq[i] = ++cnt;
    }
  }  // for(int i=1; i<=n; i++) printf("%d %d %d\n", dep[i], fson[i], eson[i]);
  dfs2(1, 0);
  for (int i = 1; i <= m; i++) {
    int sign;
    scanf("%d", &sign);
    if (sign == 1) {
      int x, d;
      scanf("%d%d", &d, &x);
      d += 1;
      if (qq[d]) {
        val[qq[d]] += x;
      } else {
        for (int j = 0; j < G[d].size(); j++) {
          change(fson[G[d][j]], x);
        }
      }
    } else {
      int a;
      scanf("%d", &a);
      long long ans;  // printf("%d %d\n", fson[a], eson[a]);
      ans = query(eson[a]) - query(fson[a] - 1);  // printf("!!%d\n", ans);
      for (int j = 1; j <= cnt; j++) ans += sonnum[a][j] * val[j];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
// zjc