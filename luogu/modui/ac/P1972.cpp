// P1972 [SDOI2009]HH的项链
// https://www.luogu.org/problemnew/show/P1972

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 1000005;
int C[MAX_N];
int n, m;

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

int num[MAX_N];
int vis[MAX_N];

struct Q {
  int l, r, i;
} Qarr[MAX_N];
bool Qcmp(Q &a, Q &b) { return a.r < b.r; }

int ans[MAX_N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &Qarr[i].l, &Qarr[i].r);
    Qarr[i].i = i;
  }
  sort(Qarr + 1, Qarr + 1 + m, Qcmp);
  int pre = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = pre; j <= Qarr[i].r; j++) {
      if (vis[num[j]] != 0) {
        change(vis[num[j]], -1);
      }
      change(j, 1);
      vis[num[j]] = j;
    }
    pre = Qarr[i].r + 1;
    ans[Qarr[i].i] = getsum(Qarr[i].r) - getsum(Qarr[i].l - 1);
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}

// 树状数组 100分