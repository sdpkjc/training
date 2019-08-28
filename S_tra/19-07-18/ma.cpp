#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int a[100005];
int b[100005];
int ax[100005];
int bx[100005];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    int k = n;
    for (int i = 0; i < n; i++) {
      while (!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
      if (!dq.empty())
        ax[i] = dq.back();
      else
        ax[i] = 0;
      dq.push_back(i);
    }
    dq.clear();
    for (int i = 0; i < n; i++) {
      while (!dq.empty() && b[i] <= b[dq.back()]) dq.pop_back();
      if (!dq.empty())
        bx[i] = dq.back();
      else
        bx[i] = 0;
      dq.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (ax[i] == bx[i])
        ans = i;
      else
        break;
    }
    cout << ans + 1 << endl;
  }

  return 0;
}