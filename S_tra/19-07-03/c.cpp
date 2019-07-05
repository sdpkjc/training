#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int arr[1000];

int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<pair<double, int> > vx;
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    sort(arr, arr + n - 1);
    for (int i = 0; i <= 100; i++) {
      double k = (double)(sum + i) / (double)(n);
      double m = k * 2 / 3;
      if (i > m) {
        vx.push_back(make_pair(0, i));
      } else {
        int eq = 0;
        int dy = 0;
        for (int j = 0; j < n - 1 && arr[j] <= m; j++) {
          if (arr[j] > i) {
            dy++;
          } else if (arr[j] == i) {
            eq++;
          }
        }
        if (dy != 0) {
          vx.push_back(make_pair(0, i));
        } else {
          vx.push_back(make_pair((1.0 / (double)(eq + 1)), i));
        }
      }
    }
    for (int i = 0; i < vx.size(); i++) {
    }
    sort(vx.rbegin(), vx.rend());
    printf("%d %.2lf\n", vx[0].second, vx[0].first);
    // cout << vx[0].second << " " << vx[0].first << endl;
  }

  return 0;
}