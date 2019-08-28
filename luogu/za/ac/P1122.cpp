// P1122 最大子树和
// https://www.luogu.org/problem/P1122

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_N = 16500;

int dp[MAX_N];
int arr[MAX_N];
bool vis[MAX_N];
vector<int> G[MAX_N];
void dfs(int x) {
  vis[x] = true;
  dp[x] = arr[x];
  for (int i = 0; i < G[x].size(); i++) {
    if (!vis[G[x][i]]) {
      dfs(G[x][i]);
      dp[x] += max(dp[G[x][i]], 0);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[b].push_back(a);
    G[a].push_back(b);
  }
  int rootx = 1;
  dfs(rootx);
  int ans = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    ans = max(dp[i], ans);
  }
  cout << ans << endl;

  return 0;
}
