// P2661-信息传递
// https://www.luogu.org/problemnew/show/P2661

#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200005;
int n;
int arr[MAXN];
int in[MAXN];
bool vis[MAXN];

int ddfs(int x) {
  vis[x] = true;
  if (!vis[arr[x]])
    return ddfs(arr[x]) + 1;
  else
    return 1;
}

int main() {
  scanf("%d", &n);

  memset(in, 0, sizeof(in));
  memset(vis, false, sizeof(vis));

  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    in[arr[i]]++;
  }
  while (true) {
    int t = -1;
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0 && !vis[i]) {
        t = i;
        vis[t] = true;
        if (!vis[arr[t]]) in[arr[t]]--;
      }
    }
    if (t == -1) break;
  }

  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ans = min(ddfs(i), ans);
    }
  }
  printf("%d\n", ans);

  return 0;
}

// 求图最小环，拓扑排序