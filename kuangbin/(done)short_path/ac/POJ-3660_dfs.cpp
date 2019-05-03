// POJ-3660 Cow Contest
// https://vjudge.net/problem/POJ-3660

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 105;
int n, m;
vector<int> ed[MAXN];
int vis[MAXN][MAXN];  // vis[i][j]表示i->j可达
void dfs(int s)       //普通的dfs算法
{
  int num = n;
  stack<int> st;
  st.push(s);
  vis[s][s] = 1;
  while (!st.empty()) {
    int now = st.top();
    st.pop();
    int len = ed[now].size();
    for (int i = 0; i < len; ++i) {
      if (vis[s][ed[now][i]] == 0) {
        st.push(ed[now][i]);
        vis[s][ed[now][i]] = 1;
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ed[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (vis[i][j] || vis[j][i]) cnt++;
    }
    if (cnt >= n - 1) {
      ans++;
    }
  }
  printf("%d\n", ans);

  return 0;
}

// 传递闭包