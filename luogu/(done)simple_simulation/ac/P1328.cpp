// P1328 生活大爆炸版石头剪刀布
// https://www.luogu.org/problemnew/show/P1328

#include <cmath>
#include <cstdio>
using namespace std;

int arra[1000];
int arrb[1000];
int vs[5][5] = {{0, 0, 1, 1, 0},
                {1, 0, 0, 1, 0},
                {0, 1, 0, 0, 1},
                {0, 0, 1, 0, 1},
                {1, 1, 0, 0, 0}};
int main() {
  int n, na, nb;
  scanf("%d%d%d", &n, &na, &nb);
  for (int i = 0; i < na; i++) {
    scanf("%d", &arra[i]);
  }
  for (int i = 0; i < nb; i++) {
    scanf("%d", &arrb[i]);
  }
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    a += vs[arra[i % na]][arrb[i % nb]];
    b += vs[arrb[i % nb]][arra[i % na]];
  }
  printf("%d %d\n", a, b);
  return 0;
}

// 水，取余