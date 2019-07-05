// P1208 [USACO1.3]混合牛奶 Mixing Milk
// https://www.luogu.org/problemnew/show/P1208

#include <algorithm>
#include <cstdio>
using namespace std;

struct goods {
  int p, a;
  bool operator<(const goods &b) const {
    if (p != b.p)
      return p < b.p;
    else
      return a > b.a;
  }
};

goods arr[5005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &arr[i].p, &arr[i].a);
  }
  sort(arr, arr + m);
  int sn = 0;
  int ans = 0;
  for (int i = 0; i < m && sn < n; i++) {
    ans += min(n - sn, arr[i].a) * arr[i].p;
    sn += min(n - sn, arr[i].a);
  }
  printf("%d\n", ans);
  return 0;
}