#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define int long long
int arr[300005];
int arrA[300005];
int arrB[300005];

signed main() {
  int n, q;
  cin >> n >> q;
  int maxx = -1;
  deque<int> Q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    Q.push_back(arr[i]);
    maxx = max(maxx, arr[i]);
  }
  int cnt = 0;
  while (Q.front() != maxx) {
    int a = Q.front();
    Q.pop_front();
    int b = Q.front();
    arrA[cnt] = a;
    arrB[cnt] = b;
    Q.pop_front();
    if (a > b) {
      Q.push_front(a);
      Q.push_back(b);
    } else {
      Q.push_front(b);
      Q.push_back(a);
    }
    cnt++;
  }
  int ii = 0;
  while (!Q.empty()) {
    arr[ii] = Q.front();
    Q.pop_front();
    ii++;
  }

  while (q--) {
    int m;
    cin >> m;
    if (m <= cnt) {
      cout << arrA[m - 1] << " " << arrB[m - 1];
    } else {
      int xx = m - cnt;
      int x = (xx - 1) % (n - 1);
      cout << maxx << " " << arr[x + 1];
    }
    cout << endl;
  }

  return 0;
}