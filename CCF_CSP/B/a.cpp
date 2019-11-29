#include <iostream>
using namespace std;

int arr[10005], ans[10005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n - 1; i++) {
    ans[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
  }
  ans[0] = (arr[0] + arr[1]) / 2;
  ans[n - 1] = (arr[n - 1] + arr[n - 2]) / 2;

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }

  return 0;
}