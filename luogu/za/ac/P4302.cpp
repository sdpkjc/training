// P4302 [SCOI2003]字符串折叠
// https://www.luogu.org/problem/P4302

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 105, INF = 0x3f3f3f3f;
int f[N][N];
char s[N];
int n;

bool check(char s[], int n, int len) {
  for (int i = len; i < n; ++i) {
    if (s[i] != s[i % len]) return false;
  }
  return true;
}

int fbit(int n) {
  if (n < 10) return 1;
  if (n < 100) return 2;
  return 3;
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; ++i) {
    f[i][i] = 1;
  }

  for (int l = 2; l <= n; ++l) {
    for (int i = 0, j; (j = i + l - 1) < n; ++i) {
      for (int k = i; k < j; ++k) {
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
      }

      for (int k = i; k < j; ++k) {
        int len = k - i + 1;
        if (l % len != 0) continue;
        if (check(s + i, l, len)) {
          f[i][j] = min(f[i][j], f[i][k] + 2 + fbit(l / len));
        }
      }
    }
  }

  printf("%d\n", f[0][n - 1]);
}
