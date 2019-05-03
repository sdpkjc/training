// HDU-1166 敌兵布阵
// https://vjudge.net/problem/HDU-1166

#include <string.h>
#include <cstdio>
using namespace std;
const int MAX_N = 50005;
int C[MAX_N];
int n;

int lowbit(int x) { return x & (-x); }
int getsum(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) {
    res += C[x];
  }
  return res;
}

void change(int x, int c) {
  for (; x <= n; x += lowbit(x)) {
    C[x] += c;
  }
}

void init() { memset(C, 0, sizeof(C)); }

int main() {
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    init();
    printf("Case %d:\n", Case);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int d;
      scanf("%d", &d);
      change(i, d);
    }
    char str[50];
    while (true) {
      scanf("%s", str);
      if (str[0] == 'E') break;
      int a, b;
      scanf("%d%d", &a, &b);
      if (str[0] == 'A') {
        change(a, b);
      } else if (str[0] == 'S') {
        change(a, -b);
      } else if (str[0] == 'Q') {
        printf("%d\n", getsum(b) - getsum(a - 1));
      }
    }
  }

  return 0;
}

// 水