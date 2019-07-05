#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1000;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int r = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - a / b * y;
  return r;
}

int CRT(int a[], int m[], int n) {
  int M = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    M *= m[i];
  }
  for (int i = 1; i <= n; i++) {
    int x, y;
    int Mi = M / m[i];
    exgcd(Mi, m[i], x, y);
    ans = (ans + Mi * x * a[i]) % M;
  }
  if (ans < 0) ans += M;
  return ans;
}

int A[maxn], M[maxn];
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> M[i] >> A[i];
  }
  if (n > 1) {
    int mx = gcd(M[1], M[2]);
    for (int i = 3; i <= n; i++) {
      mx = gcd(mx, M[i]);
    }
    int ans = CRT(A, M, n) / mx;
    if (ans > 0) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }

  } else {
    cout << A[1] << endl;
  }
  return 0;
}