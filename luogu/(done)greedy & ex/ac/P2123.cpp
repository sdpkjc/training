// P2123 皇后游戏
// https://www.luogu.org/problemnew/show/P2123

#include <algorithm>
#include <cstdio>
using namespace std;
#define int long long
struct people {
  int a, b, d;
  bool operator<(const people& tt) const {
    if (d != tt.d) return d < tt.d;
    if (d <= 0) return a < tt.a;
    return b > tt.b;
  }
};
const int MAXN = 20005;
people arr[MAXN];
int cc[MAXN];
int suma[MAXN];
signed main() {
  int T;
  scanf("%lld", &T);
  while (T--) {
    int n;
    scanf("%lld", &n);

    for (int i = 0; i < n; i++) {
      scanf("%lld%lld", &arr[i].a, &arr[i].b);
      if (arr[i].a > arr[i].b)
        arr[i].d = 1;
      else if (arr[i].a < arr[i].b)
        arr[i].d = -1;
      else
        arr[i].d = 0;
    }
    sort(arr, arr + n);
    suma[0] = arr[0].a;
    for (int i = 1; i < n; i++) {
      suma[i] = suma[i - 1] + arr[i].a;
    }
    cc[0] = arr[0].a + arr[0].b;
    int ans = cc[0];
    for (int i = 1; i < n; i++) {
      cc[i] = max(cc[i - 1], suma[i]) + arr[i].b;
      ans = max(ans, cc[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

// 好难，题解：https://www.luogu.org/problemnew/solution/P2123