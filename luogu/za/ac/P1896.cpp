// P1896 [SCOI2005]互不侵犯
// https://www.luogu.org/problem/P1896

#include <iostream>
#include <vector>
using namespace std;
int n, k;

bool check(int x, int q) {
  bool re = true;
  if ((q & x) != 0) {
    re = false;
  }
  if (((q >> 1) & x) != 0) {
    re = false;
  }
  if ((q & (x >> 1)) != 0) {
    re = false;
  }
  return re;
}
long long dp[30][2050][100];
int main() {
  cin >> n >> k;
  vector<pair<int, int> > KV;
  for (int i = 0; i < (1 << n); i++) {
    int a = i;
    int b = i >> 1;
    int c = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        c++;
      }
    }
    if ((a & b) == 0 && c <= k) KV.push_back(make_pair(a, c));
  }
  for (int i = 0; i < KV.size(); i++) {
    int S = KV[i].first;
    int Ks = KV[i].second;
    dp[1][S][Ks] += 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int Si = 0; Si < KV.size(); Si++) {
      int S = KV[Si].first;
      int Ks = KV[Si].second;
      for (int Qi = 0; Qi < KV.size(); Qi++) {
        int Q = KV[Qi].first;
        int Kq = KV[Qi].second;
        if (check(S, Q)) {
          for (int kx = Ks; kx <= k; kx++) {
            dp[i][S][kx] += dp[i - 1][Q][kx - Ks];
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < KV.size(); i++) {
    ans += dp[n][KV[i].first][k];
  }
  cout << ans << endl;
  return 0;
}