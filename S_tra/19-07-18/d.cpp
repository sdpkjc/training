#include <memory.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int a[MAXN];
int b[MAXN];

bool f(int l, int r) {
  for (int i = l; i <= r; i++) {
    for (int j = i; j <= r; j++) {
      int min1 = a[i], min2 = b[i], in1 = i, in2 = i;
      for (int k = i; k <= j; k++) {
        if (a[k] < min1) {
          min1 = a[k];
          in1 = k;
        }
        if (b[k] < min2) {
          min2 = b[k];
          in2 = k;
        }
      }
      if (in1 != in2) return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    // for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    // printf("\n");
    // for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    // printf("\n");
    for (int i = n; i >= 1; i--) {
      if (f(1, i)) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}