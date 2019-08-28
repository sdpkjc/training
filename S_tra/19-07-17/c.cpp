#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define int long long
const int MAX_N = 100010;

queue<int> Q;
signed main() {
  int nn, m, k;
  cin >> nn >> m >> k;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    Q.push(tmp);
  }

  int cnt = 0;
  int tcnt = 0;
  while (!Q.empty()) {
    int a = Q.front();
    Q.pop();
    int qj = (a - 1 - tcnt) / k;

    int ttcnt = 1;
    while (!Q.empty()) {
      int b = Q.front();
      int bqj = (b - 1 - tcnt) / k;
      if (bqj == qj) {
        ttcnt++;
        Q.pop();
      } else {
        break;
      }
    }
    tcnt += ttcnt;
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}