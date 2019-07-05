// P1214 [USACO1.4]等差数列 Arithmetic Progressions
// https://www.luogu.org/problemnew/show/P1214

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int flag[225000 * 2];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      flag[i * i + j * j] = 1;
    }
  }
  int fw = m * m * 2;
  vector<pair<int, int> > ans;
  for (int a = 0; a <= fw; a++) {
    if (flag[a]) {
      for (int b = a + 1; b <= fw; b++) {
        if (flag[b]) {
          int gc = b - a;
          if (a + gc * n - gc > fw) break;
          int f = true;
          for (int i = 2; i < n; i++) {
            int x = a + gc * i;
            if (x >= 125000 || flag[x] != 1) {
              f = false;
              break;
            }
          }
          if (f) ans.push_back(make_pair(gc, a));
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].second << " " << ans[i].first << endl;
  }
  if (ans.size() == 0) {
    cout << "NONE" << endl;
  }

  return 0;
}