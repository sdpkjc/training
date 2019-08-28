#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int arrA[100005];
int arrB[100005];
const int MAX_N = 100010;
int C[MAX_N], CC[MAX_N];
int n = MAX_N;

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

int cgetsum(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) {
    res += CC[x];
  }
  return res;
}

void cchange(int x, int c) {
  for (; x <= n; x += lowbit(x)) {
    CC[x] += c;
  }
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arrA[i]);
      C[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arrB[i]);
      CC[i] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d ", arrA[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", arrB[i]);
    printf("\n");
    arrA[0] = arrB[0] = n + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int fa = 1, fb = 1;
      if (arrA[i] < arrA[i - 1]) {
        fa = 0;
      }
      if (arrB[i] < arrB[i - 1]) {
        fb = 0;
      }
      if (fa != fb) {
        break;
      }
      int xa, xb;
      if (arrA[i] < arrA[i - 1]) {
        xa = getsum(arrA[i]);
      }
      if (arrB[i] < arrB[i - 1]) {
        xb = cgetsum(arrB[i]);
      }
      //   printf("%d %d\n", xa, xb);
      if (arrA[i] < arrA[i - 1]) {
        if (xa == xb) {
          change(arrA[i], 1);
          cchange(arrB[i], 1);
        } else {
          break;
        }
      }
      ans++;
    }

    printf("%d\n", ans);
  }

  return 0;
}