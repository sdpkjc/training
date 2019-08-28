// P1614 爱与愁的心痛
// https://www.luogu.org/problem/P1614

#include <iostream>
using namespace std;

int arr[10000];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  int ans = 0x3f3f3f3f;
  for (int i = 1; i + m - 1 <= n; i++) {
    int tans = arr[i + m - 1] - arr[i - 1];
    ans = min(ans, tans);
  }

  cout << ans << endl;

  return 0;
}