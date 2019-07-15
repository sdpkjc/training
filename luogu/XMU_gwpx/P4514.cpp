// P4514 上帝造题的七分钟
// https://www.luogu.org/problemnew/show/P4514

#include <cstdio>
#include <iostream>
using namespace std;
const int MAX_N = 2110;
int n, m;

struct BIT {
  int C[MAX_N][MAX_N];

  int lowbit(int x) { return x & (-x); }
  void change(int i, int j, int delta) {
    for (int x = i; x <= n; x += lowbit(x)) {
      for (int y = j; y <= m; y += lowbit(y)) {
        C[x][y] += delta;
      }
    }
  }
  int getsum(int i, int j) {
    int res = 0;
    for (int x = i; x; x -= lowbit(x)) {
      for (int y = j; y; y -= lowbit(y)) {
        res += C[x][y];
      }
    }
    return res;
  }
} A, Ai, Aj, Aij;
int ans(int x, int y) {
  return A.getsum(x, y) * (x * y + x + y + 1) - Ai.getsum(x, y) * (y + 1) -
         Aj.getsum(x, y) * (x + 1) + Aij.getsum(x, y);
}

void add(int x, int y, int num) {
  A.change(x, y, num);
  Ai.change(x, y, num * x);
  Aj.change(x, y, num * y);
  Aij.change(x, y, num * x * y);
}

int main() {
  char t;
  scanf(" %c %d %d", &t, &n, &m);

  while (~scanf(" %c", &t)) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (t == 'L') {
      int delta;
      scanf("%d", &delta);

      add(a, b, delta);
      add(a, d + 1, -delta);
      add(c + 1, b, -delta);
      add(c + 1, d + 1, delta);

    } else if (t == 'k') {
      printf("%d\n",
             ans(c, d) - ans(a - 1, d) - ans(c, b - 1) + ans(a - 1, b - 1));
    }
  }

  return 0;
}