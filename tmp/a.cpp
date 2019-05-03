#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int tp[100];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int x[100] = {
    0,   1,      1,      5,       1,      21,      1,       85,      73,
    341, 89,     1365,   1,       5461,   4681,    21845,   1,       87381,
    1,   349525, 299593, 1398101, 178481, 5592405, 1082401, 1082401,
};

int main() {
  tp[0] = 1;
  for (int i = 1; i < 30; i++) {
    tp[i] = tp[i - 1] * 2;
  }

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    int tmp = a;
    a--;
    for (int i = 1; i < 30; i++) {
      a -= tp[i];
      if (a == 0) {
        a = tmp;
        int ans = 0;

        for (int i = 1; i < 30; i++) {
          if (a == tp[i] - 1) {
            printf("%d\n", x[i - 1]);
          }
        }
        break;
      } else if (a < 0) {
        printf("%d\n", tp[i + 1] - 1);
        break;
      }
    }
  }
  return 0;
}