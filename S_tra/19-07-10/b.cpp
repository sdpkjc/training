#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arr[100005];
int x[100005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  arr[0] = x[n - 1];
  arr[1] = x[n - 2];
  arr[n - 1] = x[n - 3];
  for (int i = 2; i < n - 1; i++) {
    arr[i] = x[i - 2];
  }

  bool flag = true;
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] >= arr[i - 1] + arr[i + 1]) {
      flag = false;
    }
  }
  if (arr[0] >= arr[n - 1] + arr[1]) {
    flag = false;
  }
  if (arr[n - 1] >= arr[n - 2] + arr[0]) {
    flag = false;
  }

  if (flag) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (i != 0) cout << " ";
      cout << arr[i];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}