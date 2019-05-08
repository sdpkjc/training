// P1094 纪念品分组
// https://www.luogu.org/problemnew/show/P1094

#include <algorithm>
#include <cstdio>
using namespace std;

int arr[30005];
int main() {
  int w, n;
  scanf("%d%d", &w, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  int l = 0, r = n - 1;
  int ans = 0;
  while (l <= r) {
    if (arr[l] + arr[r] <= w) {
      ans++;
      l++;
      r--;
    } else {
      ans++;
      r--;
    }
  }
  printf("%d\n", ans);
  return 0;
}

// 尽量最大最小成一组，如果不行就最大的独自一组