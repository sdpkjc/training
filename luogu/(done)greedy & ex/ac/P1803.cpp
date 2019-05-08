// P1803 凌乱的yyy / 线段覆盖
// https://www.luogu.org/problemnew/show/P1803

#include <algorithm>
#include <cstdio>
using namespace std;

struct act {
  int l, r;
  bool operator<(const act& b) const {
    if (r != b.r) return r < b.r;
    return l > b.r;
  }
};

act arr[1000005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &arr[i].l, &arr[i].r);
  }
  sort(arr, arr + n);
  int now = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].l >= now) {
      now = arr[i].r;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}

// 优先选先结束的