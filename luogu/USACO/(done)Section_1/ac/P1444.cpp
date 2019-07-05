// P1444 [USACO1.3]虫洞wormhole
// https://www.luogu.org/problemnew/show/P1444

#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int ans, n, tag[30], cp[30], mnext[30];
pii arr[30];

bool cycle(int x) {
  while (mnext[x]) {
    if (tag[x]) return 1;
    tag[x] = 1;
    x = cp[mnext[x]];
  }
  return 0;
}

void dfs(int x) {
  if (x > n) {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      memset(tag, 0, sizeof(tag));
      flag |= cycle(i);
    }
    ans += flag;
  }
  if (cp[x])
    dfs(x + 1);
  else {
    for (int i = x + 1; i <= n; i++) {
      if (!cp[i]) {
        cp[i] = x;
        cp[x] = i;
        dfs(x + 1);
        cp[i] = 0;
        cp[x] = 0;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr + 1, arr + 1 + n);
  for (int i = 1; i <= n - 1; i++) {
    if (arr[i].first == arr[i + 1].first) {
      mnext[i] = i + 1;
    }
  }
  ans = 0;
  dfs(1);
  cout << ans << endl;
  return 0;
}