#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 100005;
int arr[MAX_N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    if (n <= 2) {
      cout << 0 << endl;
    } else {
      cout << min(min(arr[n - 1], arr[n - 2]) - 1, n - 2) << endl;
    }
  }
  return 0;
}