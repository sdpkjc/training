// P2014 选课
// https://www.luogu.org/problemnew/show/P2014

#include <string.h>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 400;
int W[MAXN];
int dp[400][6005];
int T, M;
vector<int> G[MAXN];

int dfs(int x) {
  int sum = 0;
  for (int i = 0; i < G[x].size(); i++) {
    int t = dfs(G[x][i]);
    sum += (t + 1);
    for (int j = sum; j >= 0; j--) {
      for (int k = 0; k <= t; k++) {
        if (j - k - 1 >= 0)
          dp[x][j] = max(dp[x][j], dp[x][j - k - 1] + dp[G[x][i]][k]);
      }
    }
  }
  return sum;
}
int main() {
  memset(dp, 0, sizeof(dp));
  scanf("%d%d", &M, &T);
  for (int i = 1; i <= M; i++) {
    int tmp;
    scanf("%d%d", &tmp, &W[i]);
    dp[i][0] = W[i];
    G[tmp].push_back(i);
  }
  dfs(0);

  printf("%d\n", dp[0][T]);
  return 0;
}
