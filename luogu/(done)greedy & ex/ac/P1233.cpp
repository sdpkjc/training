// P1233 木棍加工 nn
// https://www.luogu.org/problemnew/show/P1233

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct goods {
  int a, b;

  bool operator<(const goods& tt) const {
    if (a != tt.a) return a > tt.a;
    return b > tt.b;
  }
};
goods a[100005];
int dpb[100005];

int n;

int bLIS_nn() {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    dpb[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (!(a[j].a >= a[i].a && a[j].b >= a[i].b)) {
        dpb[i] = max(dpb[i], dpb[j] + 1);
      }
    }
    ans = max(ans, dpb[i]);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].a, &a[i].b);
  }
  sort(a + 1, a + n + 1);
  int ans2 = bLIS_nn();
  printf("%d\n", ans2);

  return 0;
}

// 排序后，最长xxx子序列，P1020 导弹拦截
// Dilworth定理：偏序集的最少反链划分数等于最长链的长度