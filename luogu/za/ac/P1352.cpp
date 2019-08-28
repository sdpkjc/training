// P1352 没有上司的舞会
// https://www.luogu.org/problem/P1352

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_N = 6500;

int dp[MAX_N][2];
int arr[MAX_N];
bool vis[MAX_N];
vector<int> G[MAX_N];
void dfs(int x) {
  dp[x][0] = 0;
  dp[x][1] = arr[x];
  for (int i = 0; i < G[x].size(); i++) {
    dfs(G[x][i]);
    dp[x][0] += max(dp[G[x][i]][0], dp[G[x][i]][1]);
    dp[x][1] += dp[G[x][i]][0];
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
    vis[a] = true;
  }
  int rootx;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      rootx = i;
      break;
    }
  }
  dfs(rootx);
  cout << max(dp[rootx][0], dp[rootx][1]) << endl;

  return 0;
}