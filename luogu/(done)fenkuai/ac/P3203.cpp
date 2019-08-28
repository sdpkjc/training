// P3203 [HNOI2010]弹飞绵羊
// https://www.luogu.org/problem/P3203

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int arr[200005];
int step[200005];
int nextb[200005];

struct block {
  int l, r;
} B[200005];
int cntb = 0;

int wk(int x) {
  int kk = x / k;
  if(kk >= cntb) return -1;
  if (x >= B[kk].l && x <= B[kk].r) {
    return kk;
  }
  return -1;
}

void up(int ib) {
  int l = B[ib].l, r = B[ib].r;
  step[r] = 1;
  nextb[r] = r + arr[r];
  for (int i = r - 1; i >= l; i--) {
    int w = wk(i + arr[i]);
    if (w == ib) {
      step[i] = step[i + arr[i]] + 1;
      nextb[i] = nextb[i + arr[i]];
    } else {
      step[i] = 1;
      nextb[i] = i + arr[i];
    }
  }
}
int main() {
  cin >> n;
  k = sqrt(200005);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i += k) {
    B[cntb].l = i;
    B[cntb].r = min(i + k - 1, n - 1);
    cntb++;
  }
  for (int i = 0; i < cntb; i++) {
    up(i);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int q;
      cin >> q;
      int sum = 0;
      for (int j = q;;) {
        sum += step[j];
        if (wk(nextb[j]) == -1) {
          break;
        }
        j = nextb[j];
      }
      cout << sum << endl;
    } else if (cmd == 2) {
      int ind, kk;
      cin >> ind >> kk;
      arr[ind] = kk;
      int w = wk(ind);
      up(w);
    }
  }
  return 0;
}