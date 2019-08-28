#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int MOD = 998244353;
#define LL long long

LL exgcd(LL a, LL b, LL &x, LL &y)  //扩展欧几里得算法
{
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  LL ret = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
}
LL getInv(int a, int mod)  //求a在mod下的逆元，不存在逆元返回-1
{
  LL x, y;
  LL d = exgcd(a, mod, x, y);
  return d == 1 ? (x % mod + mod) % mod : -1;
}

int main() {
  int N;
  cin >> N;
  cout << (N + 1) % MOD * getInv(2, MOD) % MOD * N % MOD << endl;
  return 0;
}
