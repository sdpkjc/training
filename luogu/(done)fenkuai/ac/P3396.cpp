// P3396 哈希冲突
// https://www.luogu.org/problem/P3396

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m, k;
int arr[150005];
int val[400][400];
int main() {
  cin >> n >> m;
  k = (int)sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      val[i][j % i] += arr[j];
    }
  }
  for (int i = 0; i < m; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'A') {
      if (a <= k) {
        cout << val[a][b];
      } else {
        int ans = 0;
        for (int j = b; j <= n; j += a) {
          ans += arr[j];
        }
        cout << ans;
      }
      cout << endl;
    } else if (c == 'C') {
      for (int j = 1; j <= k; j++) {
        val[j][a % j] -= arr[a];
        val[j][a % j] += b;
      }
      arr[a] = b;
    }
  }
  return 0;
}