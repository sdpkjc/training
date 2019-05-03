// P2921 [USACO08DEC]在农场万圣节Trick or Treat on the Farm
// https://www.luogu.org/problemnew/show/P2921

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 100005;
int n, nxt[MAXN], color[MAXN], sucdfn[MAXN], dfn[MAXN], minc[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> nxt[i];
  }
  memset(color, 0, sizeof(color));
  memset(dfn, 0, sizeof(dfn));
  memset(minc, 0, sizeof(minc));
  for (int c = 1; c <= n; c++) {
    for (int i = c, cnt = 0;; i = nxt[i], cnt++) {
      if (!color[i]) {
        color[i] = c;
        dfn[i] = cnt;
        continue;
      } else if (color[i] == c) {
        minc[c] = cnt - dfn[i];
        sucdfn[c] = dfn[i];
        cout << cnt << endl;
      } else {
        minc[c] = minc[color[i]];
        sucdfn[c] = cnt + max(sucdfn[color[i]] - dfn[i], 0);
        cout << sucdfn[c] + minc[c] << endl;
      }
      break;
    }
  }

  return 0;
}

// 计算图环大小，两种环
// 题解：https://www.luogu.org/blog/planetarian/solution-p2921