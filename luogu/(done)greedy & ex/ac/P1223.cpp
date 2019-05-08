// P1223 排队接水
// https://www.luogu.org/problemnew/show/P1223

#include <algorithm>
#include <cstdio>
using namespace std;

struct people {
  int t, dex;
  bool operator<(const people& b) const {
    if (t != b.t) return t < b.t;
    return dex < b.dex;
  }
};

people arr[1005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].t);
    arr[i].dex = i;
  }
  sort(arr, arr + n);
  int sj = 0;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += sj;
    sj += arr[i].t;
    if (i != 0) printf(" ");
    printf("%d", arr[i].dex + 1);
  }
  if (n != 0)
    printf("\n%.2lf\n", sum / n);
  else
    printf("\n0\n");

  return 0;
}

// 浮点数精度