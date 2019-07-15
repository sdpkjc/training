#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int arr[1000005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 1;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1]) {
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 1;
    }
  }
  cout << ans << endl;
  return 0;
}