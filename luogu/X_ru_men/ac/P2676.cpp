// P2676 超级书架
// https://www.luogu.org/problem/P2676

#include <algorithm>
#include <iostream>
using namespace std;

int arr[20005];

int main() {
  long long n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long ans = 0, sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (sum >= x) {
      break;
    }
    sum += arr[i];
    ans++;
  }
  cout << ans << endl;
  return 0;
}