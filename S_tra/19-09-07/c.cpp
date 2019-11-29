#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int a[1000005];
int b[1000005];
int p[2000005];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int Vy[2000005];
int kx;
int yh(int y) { return lower_bound(Vy, Vy + kx, y) - Vy; }

int main() {
  int n, m, x, y, z, id = 0;
  scanf("%d%d", &n, &m);
  int vys = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    Vy[vys++] = b[i];
    Vy[vys++] = b[i] + 1;
  }
  for (int i = 0; i < 2000005; i++) {
    p[i] = i;
  }
  sort(Vy, Vy + vys);
  kx = unique(Vy, Vy + vys) - Vy;
  for (int i = 1; i <= m; i++) {
    y = yh(b[i]);
    if (a[i] == 1) {
      y = find(y);
      z = find(y + 1);
      if (y > z) swap(y, z);
      if (y != z) p[y] = z;
    } else {
      printf("%d\n", Vy[find(p[y])]);
    }
  }
  return 0;
}