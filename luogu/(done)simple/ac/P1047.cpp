#include <iostream>
using namespace std;

int flag[10005];

int main() {
  int L, m;
  cin >> L >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a; j <= b; j++) {
      flag[j] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i <= L; i++) {
    if (!flag[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}