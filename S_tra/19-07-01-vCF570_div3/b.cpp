#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int arr[200];

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    int minx = 0x3f3f3f3f, maxx = 0xbfbfbfbf;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] > maxx) {
        maxx = arr[i];
      }
      if (arr[i] < minx) {
        minx = arr[i];
      }
    }

    if (maxx - minx > 2 * k) {
      cout << -1 << endl;
    } else {
      cout << minx + k << endl;
    }
  }

  return 0;
}