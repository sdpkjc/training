// P1140 相似基因
// https://www.luogu.org/problemnew/show/P1140

#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200;
char a[MAXN];
char b[MAXN];
int aa[MAXN];
int bb[MAXN];
int dp[MAXN][MAXN];

int arr[5][5] = {{5, -1, -2, -1, -3},
                 {-1, 5, -3, -2, -4},
                 {-2, -3, 5, -2, -2},
                 {-1, -2, -2, 5, -1},
                 {-3, -4, -2, -1, 0}};

int main() {
  int al, bl;
  scanf("%d", &al);
  scanf("%s", a + 1);
  scanf("%d", &bl);
  scanf("%s", b + 1);
  for (int i = 1; i <= al; i++) {
    for (int j = 1; j <= bl; j++) {
      dp[i][j] = -INF;
    }
  }
  for (int i = 1; i <= al; i++) {
    if (a[i] == 'A') aa[i] = 0;
    if (a[i] == 'C') aa[i] = 1;
    if (a[i] == 'G') aa[i] = 2;
    if (a[i] == 'T') aa[i] = 3;
  }

  for (int i = 1; i <= bl; i++) {
    if (b[i] == 'A') bb[i] = 0;
    if (b[i] == 'C') bb[i] = 1;
    if (b[i] == 'G') bb[i] = 2;
    if (b[i] == 'T') bb[i] = 3;
  }

  for (int i = 1; i <= al; i++) {
    dp[i][0] = dp[i - 1][0] + arr[aa[i]][4];
  }
  for (int i = 1; i <= al; i++) {
    dp[0][i] = dp[0][i - 1] + arr[bb[i]][4];
  }
  for (int i = 1; i <= al; i++) {
    for (int j = 1; j <= bl; j++) {
      dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[bb[j]][4]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[aa[i]][4]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[aa[i]][bb[j]]);
    }
  }

  printf("%d\n", dp[al][bl]);
  return 0;
}

// 处理 _ ，dp[i][j] -> 第一个碱基序列的第i位对应到第二个碱基的第j位的最大值