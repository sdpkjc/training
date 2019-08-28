#include <iostream>
using namespace std;

int arr[100005];

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    while (true) {
      int c;
      cin >> c;
      if (c == 0) break;
      arr[i] = max(arr[i], arr[c]);
    }
    arr[i] += b;
    ans = max(ans, arr[i]);
  }
  cout << ans << endl;
  return 0;
}