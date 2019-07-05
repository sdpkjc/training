#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
long long a[100010], r[100010], x, y;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long p = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - (a / b) * y;
  return p;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    bool flag = 1;
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &r[i]);
    for (int i = 1; i < n; i++) {
      x = 0, y = 0;
      long long d = exgcd(a[i], a[i + 1], x, y), t = a[i + 1] / d;
      if ((r[i + 1] - r[i]) % d) {
        flag = 0;
        break;
      } else {
        x = x * ((r[i + 1] - r[i]) / d);
        x = (x % t + t) % t;
        r[i + 1] = a[i] * x + r[i];
        a[i + 1] = a[i] * a[i + 1] / d;
        r[i + 1] %= a[i + 1];
      }
    }
    if (!flag)
      printf("-1\n");
    else
      printf("%lld\n", r[n]);
  }
  return 0;
}