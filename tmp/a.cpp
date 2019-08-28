#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct X {
  int t, c;
  bool operator<(const X& x) const {
    if (t == x.t) {
      return c > x.c;
    }
    return t > x.t;
  }
} arr[200];

int main() {
  int m, n, x;
  while (cin >> m >> n >> x) {
    priority_queue<X> Q;
    for (int i = 0; i < n; i++) {
      cin >> arr[i].c;
      arr[i].t = 0;
      Q.push(arr[i]);
    }
    int cnt = m, cntx = 0;
    while (!Q.empty()) {
      X tmp = Q.top();
      Q.pop();
      if (cnt < 1) break;
      if (tmp.t >= x) break;
      tmp.t += tmp.c;
      if (tmp.t <= x) {
        Q.push(tmp);
        cnt--;
      } else {
        cnt--;
        cntx++;
      }
    }
    cout << cnt << " " << cntx << endl;
  }

  return 0;
}