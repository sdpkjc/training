#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100100;
int C[MAX_N];
int n = MAX_N - 20;

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

struct P {
  int x, y;
  char c;
} Parr[100005];
int Vy[100005];

int nn, m, k;

int yh(int y) { return lower_bound(Vy, Vy + k, y) - Vy; }

bool cmpx(const P &a, const P &b) { return a.x < b.x; }

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    scanf("%d%d%d", &nn, &m, &k);
    // nn = Scan();
    // m = Scan();
    // k = Scan();
    n = k + 5;

    for (int i = 0; i < k; i++) {
      scanf("%d%d %c", &Parr[i].x, &Parr[i].y, &Parr[i].c);

      Vy[i] = Parr[i].y;
    }
    sort(Vy, Vy + k);
    sort(Parr, Parr + k, cmpx);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      C[i] = 0;
    }
    for (int i = 0; i < k; i++) {
      Parr[i].y = yh(Parr[i].y) + 1;
    }
    for (int i = 0; i < k; i++) {
      if (Parr[i].c == 'U') {
        ans += (getsum(k) - getsum(Parr[i].y));
      } else if (Parr[i].c == 'D') {
        ans += (getsum(Parr[i].y));
      } else if (Parr[i].c == 'R') {
        change(Parr[i].y, 1);
      }
    }
    for (int i = 0; i <= n; i++) {
      C[i] = 0;
    }
    for (int i = k - 1; i >= 0; i--) {
      if (Parr[i].c == 'U') {
        ans += (getsum(k) - getsum(Parr[i].y));
      } else if (Parr[i].c == 'D') {
        ans += (getsum(Parr[i].y));
      } else if (Parr[i].c == 'L') {
        change(Parr[i].y, 1);
      }
    }
    printf("%d\n", ans + 1);
    // Out(ans + 1);
    // putchar('\n');
  }
  return 0;
}