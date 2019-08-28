// P1296 奶牛的耳语
// https://www.luogu.org/problem/P1296

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> V;
int main() {
  int n, d, ans = 0;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    V.push_back(tmp);
  }
  sort(V.rbegin(), V.rend());
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(V[j] - V[i]) <= d)
        ans++;
      else
        break;
    }
  }
  cout << ans << endl;
  return 0;
}