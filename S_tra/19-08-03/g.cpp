#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

bool isp(int y) {
  if (y % 4 == 0 && y % 100 != 0) return true;
  if (y % 400 == 0) return true;
  return false;
}

int whatday(int y, int m, int d) {
  // 返回正确的星期。用 0 - 6 表示 星期 1 - 7
  if (y < 1600 || y > 9999) return 1;
  if (m < 1 || m > 12) return 1;
  if (d < 1 || d > 31) return 1;
  if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) &&
      d > 31)
    return 1;
  if (!(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) &&
      d > 30)
    return 1;
  if (m == 2) {
    if (isp(y)) {
      if (d > 29) return 1;
    } else {
      if (d > 28) return 1;
    }
  }
  if (m == 1 || m == 2) {
    y--;
    m += 12;
  }
  int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
  return w;
}
vector<string> V;
int x;
bool judge(string arr) {
  for (int j = 0; j < x; j++) {
    int y, m, d;

    y = (arr[V[j][0] - 'A'] - '0') * 1000 + (arr[V[j][1] - 'A'] - '0') * 100 +
        (arr[V[j][2] - 'A'] - '0') * 10 + (arr[V[j][3] - 'A'] - '0');
    m = (arr[V[j][5] - 'A'] - '0') * 10 + (arr[V[j][6] - 'A'] - '0');
    d = (arr[V[j][8] - 'A'] - '0') * 10 + (arr[V[j][9] - 'A'] - '0');
    if (whatday(y, m, d) != 4) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    V.clear();
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      string a;
      cin >> a;
      V.push_back(a);
    }
    sort(V.begin(), V.end());
    x = unique(V.begin(), V.end()) - V.begin();
    string ans = "0123456789";
    bool fg = false;
    do {
      if (judge(ans)) {
        fg = true;
        break;
      }
    } while (next_permutation(ans.begin(), ans.end()));
    if (!fg)
      cout << "Impossible";
    else
      cout << ans;
    cout << endl;
  }
}