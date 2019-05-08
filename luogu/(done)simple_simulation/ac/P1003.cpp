// P1003 铺地毯
// https://www.luogu.org/problemnew/show/P1003

#include <cstdio>
using namespace std;

struct dt {
  int a, b, g, k;
  bool in(int x, int y) {
    if (a <= x && x <= a + g && b <= y && y <= b + k) {
      return true;
    }
    return false;
  }
} arr[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, g, k;
    scanf("%d%d%d%d", &arr[i].a, &arr[i].b, &arr[i].g, &arr[i].k);
  }
  int x, y;
  scanf("%d%d", &x, &y);
  int ans = -1;
  for (int i = n; i >= 1; i--) {
    if (arr[i].in(x, y)) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}

// 水