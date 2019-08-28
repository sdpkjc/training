#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 400;
int a[MAXN];

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int id = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 1) id = i;
    }
    int cnt = 1;
    bool f = 1, h = 1;
    for (int i = id; i < id + n; i++) {
      if (a[i % n] == cnt) {
        cnt++;
      } else {
        f = 0;
        break;
      }
    }
    cnt = 1;
    for (int i = id;; i--) {
      if (i < 0) i += n;
      if (a[i] == cnt) {
        cnt++;
      } else {
        h = 0;
        break;
      }
      if (cnt == n + 1) break;
    }
    if (f || h)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}