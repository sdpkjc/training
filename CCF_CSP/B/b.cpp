#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int flag[1000005];

int main() {
  int n;
  cin >> n;
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a; j < b; j++) {
      flag[j]++;
    }
    maxx = max(maxx, b);
  }

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a; j < b; j++) {
      flag[j]++;
    }

    maxx = max(maxx, b);
  }
  int cnt = 0;
  for (int i = 1; i < maxx; i++) {
    // cout << flag[i] << endl;
    if (flag[i] == 2) cnt++;
  }
  cout << cnt << endl;
  return 0;
}