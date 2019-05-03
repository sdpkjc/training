// P1757 通天之分组背包
// https://www.luogu.org/problemnew/show/P1757

#include <string.h>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2000;
int V[MAXN], W[MAXN];
int dp[20005];
vector<int> G[MAXN];
int main() {
  memset(dp, 0, sizeof(dp));
  int T, M;
  scanf("%d%d", &T, &M);
  for (int i = 1; i <= M; i++) {
    int tmp;
    scanf("%d%d%d", &V[i], &W[i], &tmp);
    G[tmp].push_back(i);
  }

  for (int i = 1; i <= M; i++) {
    for (int j = T; j >= 0; j--) {
      for (int k = 0; k < G[i].size(); k++) {
        if (j >= V[G[i][k]])
          dp[j] = max(dp[j], dp[j - V[G[i][k]]] + W[G[i][k]]);
      }
    }
  }
  printf("%d\n", dp[T]);
  return 0;
}

// 分组背包，01背包