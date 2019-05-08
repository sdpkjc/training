// P1181 数列分段Section I
// https://www.luogu.org/problemnew/show/P1181

#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
  int n, ma;
  scanf("%d%d", &n, &ma);
  int sum = 0;
  int cnt = 0;
  if (n != 0) cnt++;
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    if (sum + tmp <= ma) {
      sum += tmp;
    } else {
      sum = tmp;
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}

// 随便贪一下
