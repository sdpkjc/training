#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int arr[1005];

int a[1205];
int main() {
  int n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < 4 * n; i++) cin >> a[i];
    sort(a, a + 4 * n);
    bool flag = true;
    if (a[0] != a[1] || a[4 * n - 2] != a[4 * n - 1]) flag = false;
    int ans = a[0] * a[4 * n - 1];
    int i = 2;
    while (i < 2 * n) {
      if (a[i] != a[i + 1] || a[4 * n - i - 1] != a[4 * n - i - 2])
        flag = false;
      if (ans != a[i] * a[4 * n - i - 1]) flag = false;
      i += 2;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}