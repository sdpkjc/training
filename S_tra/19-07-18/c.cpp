#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int arrA[100005];
int arrB[100005];
const int MAX_N = 100010;
int C[MAX_N][2];
int n = MAX_N;

int lowbit(int x) { return x & (-x); }
int getsum(int x, int f) {
  int res = 0;
  for (; x; x -= lowbit(x)) {
    res += C[x][f];
  }
  return res;
}

void change(int x, int c, int f) {
  for (; x <= n; x += lowbit(x)) {
    C[x][f] += c;
  }
}

int main() {
  int n;

  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arrA[i]);
      C[i][0] = C[i][1] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arrB[i]);
    }
    arrA[0] = arrB[0] = n + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    }

    printf("%d\n", ans);
  }

  return 0;
}