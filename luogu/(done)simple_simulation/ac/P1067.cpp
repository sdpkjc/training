// P1067 多项式输出
// https://www.luogu.org/problemnew/show/P1067

#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  bool flag = false;
  for (int i = n; i >= 0; i--) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp == 0) continue;
    if (tmp < 0) {
      printf("-");
    } else if (flag) {
      printf("+");
    }
    flag = true;
    if (i != 0) {
      if (tmp > 1) {
        printf("%d", tmp);
      } else if (tmp < -1) {
        printf("%d", -tmp);
      }
    }
    if (i >= 1) {
      if (i != 1)
        printf("x^%d", i);
      else
        printf("x");
    } else {
      if (tmp > 0) {
        printf("%d", tmp);
      } else if (tmp < 0) {
        printf("%d", -tmp);
      }
    }
  }
  printf("\n");
  return 0;
}

// 情况有点多哟