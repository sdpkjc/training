// P1138 第k小整数
// https://www.luogu.org/problem/P1138

#include <algorithm>
#include <iostream>
using namespace std;

int arr[100005];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int m = unique(arr, arr + n) - arr;
  if (k > m) {
    cout << "NO RESULT";
  } else {
    cout << arr[k - 1];
  }
  cout << endl;
  return 0;
}