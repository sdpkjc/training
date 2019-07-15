#include <iostream>
using namespace std;

int flag[10005];
int ans[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> flag[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (flag[j] < flag[i]) {
        ans[i]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}