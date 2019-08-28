// P1116 车厢重组
// https://www.luogu.org/problem/P1116

#include <iostream>
using namespace std;

const int MAX_N = 100100;
int C[MAX_N];
int n;

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

int main() {
  int nn;
  cin >> nn;
  n = 100005;
  int ans = 0;
  for (int i = 1; i <= nn; ++i) {
    int d;
    cin >> d;
    change(d, 1);
    ans += (getsum(n) - getsum(d));
    // cout << getsum(n) - getsum(d) << endl;
  }
  cout << ans << endl;

  return 0;
}