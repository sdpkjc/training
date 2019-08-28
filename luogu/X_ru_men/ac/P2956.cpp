// P2956 [USACO09OCT]机器人犁田The Robot Plow
// https://www.luogu.org/problem/P2956

#include <iostream>
using namespace std;

int M[300][300];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j <= c; j++) {
      for (int jj = b; jj <= d; jj++) {
        M[j][jj] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (M[i][j]) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}