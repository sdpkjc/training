#include <iostream>
using namespace std;

int arr[1000];
int sum[1000];

int main() {
  int n;
  cin >> n;
  arr[1] = 1;
  sum[1] = 1;
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    arr[i] = (sum[i] + arr[i - 1] * (i - 1));
    sum[i] = sum[i - 1] + arr[i];
    // for (int j = 1; j < i; j++) {
    // }
    arr[i] %= i;
    // ans = (ans + arr[i]) % n;
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << arr[i] << endl;
  }
  cout << endl;

  return 0;
}