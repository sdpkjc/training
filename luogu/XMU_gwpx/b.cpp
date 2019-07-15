// luogu-judger-enable-o2
#include <cstdio>

int n, m, num, x1, y1, x2, y2;
char c[3];

struct BIT {
  int tree[2050][2050];

  int lowbit(int x) { return x & -x; }

  void add(int x, int y, int num) {
    for (int i = x; i <= n; i += lowbit(i))
      for (int j = y; j <= m; j += lowbit(j)) tree[i][j] += num;
  }

  int query(int x, int y) {
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
      for (int j = y; j >= 1; j -= lowbit(j)) res += tree[i][j];
    return res;
  }
} A, Ai, Aj, Aij;

int read() {
  int sign = 1, res = 0;
  char c;
  while ((c = getchar()) < 48 || c > 57)
    if (c == '-') sign = -1;
  if (sign) res = c - 48;
  while ((c = getchar()) >= 48 && c <= 57) res = res * 10 + c - 48;
  return res * sign;
}

int Ans(int x, int y) {
  return A.query(x, y) * (x * y + x + y + 1) - Ai.query(x, y) * (y + 1) -
         Aj.query(x, y) * (x + 1) + Aij.query(x, y);
}

void Add(int x, int y, int num) {
  A.add(x, y, num);
  Ai.add(x, y, num * x);
  Aj.add(x, y, num * y);
  Aij.add(x, y, num * x * y);
}

int main() {
  scanf("X %d %d", &n, &m);
  while (~scanf("%s", &c)) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (c[0] == 'L') {
      scanf("%d", &num);
      Add(x1, y1, num);
      Add(x1, y2 + 1, -num);
      Add(x2 + 1, y1, -num);
      Add(x2 + 1, y2 + 1, num);
    } else {
      printf("%d %d %d %d\n", Ans(x2, y2), Ans(x1 - 1, y2), Ans(x2, y1 - 1),
             Ans(x1 - 1, y1 - 1));
      printf("%d\n", Ans(x2, y2) - Ans(x1 - 1, y2) - Ans(x2, y1 - 1) +
                         Ans(x1 - 1, y1 - 1));
    }
  }
  return 0;
}