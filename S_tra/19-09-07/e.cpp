#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define LL long long
char s[600010], ss[600010];
int sa[600010], Xrank[600010], height[600010], cnt[600010], t1[600010],
    t2[600010], n, mn[600010][22], mx[600010][22], f[600010], kk[600010];
int min(int x, int y) { return x < y ? x : y; }
LL max(LL x, LL y) { return x > y ? x : y; }
void init() {
  int i, tem = 0;
  char c = getchar();
  while (c >= 'a' && c <= 'z') {
    ss[++tem] = c;
    c = getchar();
  }
  n = 2 * tem + 1;
  for (i = 1; i <= n; i++)
    if (i & 1)
      s[i] = '$';
    else
      s[i] = ss[i / 2];
}
void make_sa() {
  int i, j, k, p, m = 'z', *x = t1, *y = t2, *z;
  for (i = 1; i <= n; i++) cnt[x[i] = s[i]]++;
  for (i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
  for (i = n; i; i--) sa[cnt[x[i]]--] = i;
  for (k = 1; k <= n; k <<= 1) {
    p = 0;
    for (i = n - k + 1; i <= n; i++) y[++p] = i;
    for (i = 1; i <= n; i++)
      if (sa[i] - k >= 1) y[++p] = sa[i] - k;
    for (i = 1; i <= m; i++) cnt[i] = 0;
    for (i = 1; i <= n; i++) cnt[x[y[i]]]++;
    for (i = 2; i <= m; i++) cnt[i] += cnt[i - 1];
    for (i = n; i; i--) sa[cnt[x[y[i]]]--] = y[i];
    z = x;
    x = y;
    y = z;
    p = x[sa[1]] = 1;
    for (i = 2; i <= n; i++) {
      if (y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]) p++;
      x[sa[i]] = p;
    }
    if ((m = p) >= n) break;
  }
  for (i = 1; i <= n; i++) Xrank[sa[i]] = i;
  for (i = 1, k = 0; i <= n; i++) {
    if (k) k--;
    if (Xrank[i] == 1) continue;
    while (s[i + k] == s[sa[Xrank[i] - 1] + k]) k++;
    height[Xrank[i]] = k;
  }
  for (i = 1; i <= n; i++) mn[i][0] = height[i];
  for (k = 1; (1 << k) <= n; k++)
    for (i = 1; i + (1 << k) - 1 <= n; i++)
      mn[i][k] = min(mn[i][k - 1], mn[i + (1 << k - 1)][k - 1]);
  kk[0] = -1;
  for (i = 1; i <= n; i++) kk[i] = (i & i - 1) ? kk[i - 1] : kk[i - 1] + 1;
}
int get(int x, int y) {
  if (x == y) return n - sa[x] + 1;
  x++;
  int k = kk[y - x + 1];
  return min(mn[x][k], mn[y - (1 << k) + 1][k]);
}
int qry(int p, int l) {
  int ll, rr, mid, ret = 0;
  ll = 1;
  rr = p;
  while (ll < rr) {
    mid = (ll + rr) / 2;
    if (get(mid, p) >= l)
      rr = mid;
    else
      ll = mid + 1;
  }
  ret += p - ll + 1;
  ll = p;
  rr = n;
  while (ll < rr) {
    mid = (ll + rr + 1) / 2;
    if (get(p, mid) >= l)
      ll = mid;
    else
      rr = mid - 1;
  }
  return ret + ll - p;
}
LL solve() {
  int mx = 0, id = 0, i, j, k, x;
  LL ans = 0;
  for (i = 1; i <= n; i++) {
    if (mx >= i)
      f[i] = min(mx - i, f[2 * id - i]);
    else
      f[i] = 0;
    while (i - f[i] - 1 >= 1 && i + f[i] + 1 <= n &&
           s[i + f[i] + 1] == s[i - f[i] - 1])
      f[i]++;
    if (i + f[i] > mx) {
      for (x = mx - i + 2; x <= f[i]; x += 2) {
        ans = ans + (LL)qry(Xrank[i - x], 2 * x + 1) * x;
        //   cout << (LL)qry(Xrank[i - x], 2 * x + 1) << endl;
      }
      mx = i + f[i];
      id = i;
    }
  }
  return ans;
}
int main() {
  init();
  make_sa();
  printf("%lld\n", solve());
}