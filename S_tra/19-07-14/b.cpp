#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// char M[50005][50005];
vector<vector<int> > M;
int sumn[50005], summ[50005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    M.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      vector<int> vt;
      for (int j = 0; j < m; j++) {
        char x;
        cin >> x;
        if (x == '*') {
          vt.push_back(1);
          //   M[i][j] = 1;
        } else {
          vt.push_back(0);
          //   M[i][j] = 0;
        }
      }
      M.push_back(vt);
    }

    for (int i = 0; i < n; i++) {
      sumn[i] = 0;
      for (int j = 0; j < m; j++) {
        sumn[i] += M[i][j];
      }
    }
    for (int i = 0; i < m; i++) {
      summ[i] = 0;
      for (int j = 0; j < n; j++) {
        summ[i] += M[j][i];
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int tmp = sumn[i] + summ[j] - M[i][j];

        ans = min(n + m - tmp, ans);
      }
    }
    cout << ans - 1 << endl;
  }

  return 0;
}