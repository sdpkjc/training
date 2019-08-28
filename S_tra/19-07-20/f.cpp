#include <memory.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;

typedef long long ll;

int n, m, ans[30];

int a[30];

bool vis[30];

int x = 0;
void dfs(int d, int cnt) {
  if (cnt == m) {
    // for (int i = 0; i<m; i++) cout << ans[i] << " ";
    // cout << endl;
    x++;
    return;
  }
  for (int i = d; i < n; i++) {
    ans[cnt] = a[i];
    dfs(i + 1, cnt + 1);
  }
}
int main() {
  while (cin >> n >> m) {
    fill(vis, vis + 15, 0);
    for (int i = 0; i < n; i++) a[i] = i;
    dfs(0, 0);
    cout << x << endl;
    cout << "OK\n" << endl;
  }
  return 0;
}