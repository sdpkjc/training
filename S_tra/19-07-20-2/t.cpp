#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int arr[1000];
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  if (arr[0] * 2 > sum) {
    cout << 1 << endl << 1 << endl;
  } else {
    int cnt = 1;
    int x = 0;
    int f = false;
    for (int i = 1; i < n; i++) {
      if (arr[i] * 2 <= arr[0]) {
        cnt++;
        x += arr[i];
        if ((arr[0] + x) * 2 > sum) {
          f = true;
          break;
        }
      }
    }
    if (f) {
      cout << cnt << endl;
      cout << 1;
      x = 0;
      for (int i = 1; i < n; i++) {
        if (arr[i] * 2 <= arr[0]) {
          cout << " " << i + 1;
          x += arr[i];
          if ((arr[0] + x) * 2 > sum) {
            break;
          }
        }
      }
      cout << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
