// P1317 低洼地
// https://www.luogu.org/problem/P1317

#include <iostream>
#include <vector>
using namespace std;

int arr[10005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> V;
  int cnt = 0;
  if (arr[1] - arr[0] > 0) {
    V.push_back(1);
  } else {
    V.push_back(0);
    // cnt++;
  }
  for (int i = 2; i < n; i++) {
    int t;
    if (arr[i] - arr[i - 1] > 0) {
      t = 1;
    } else {
      t = 0;
    }
    if (t != V[V.size() - 1]) {
      V.push_back(t);
      if (t == 1) {
        cnt++;
        // cout << i - 1 << endl;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}