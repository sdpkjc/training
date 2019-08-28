#include <limits.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int arr[2000];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    arr[t]++;
  }

  int ans = n;
  if (n % 2 == 1) {
    ans++;
  }
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    // if (arr[i] != 0) cout << i << " " << arr[i] << endl;
    if (arr[i] % 2 == 1) {
      ans--;
      cnt++;
    }
  }
  cout << min(ans + cnt / 2, n) << endl;

  return 0;
}