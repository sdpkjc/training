#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  //   for (int i = 1; i < 100; i++) {
  //     int sum = 0;
  //     for (int j = 1; j <= i; j++) {
  //       sum += j * (i % j);
  //     }
  //     cout << i << " " << sum << endl;
  //   }
  int sumx = 0;
  for (int i = 1; i <= 10; i++) {
    for (int j = 2; j <= i; j++) {
      sumx += j;
    }
  }
  cout << sumx << endl;
  int n, m;
  int sum = 0;
  cin >> n >> m;
  vector<int> V;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i * j * (n % i) * (m % j) != 0) {
        // cout << i << " " << j << " " << (n % i) << " " << (m % j) << endl;
        // cout << i * j * (n % i) * (m % j) << endl;
        // V.push_back(i * j * (n % i) * (m % j));
      }
      sum += (i * j * (n % i) * (m % j) % MOD);
    }
  }
  cout << sum << endl;
  //   cout << V.size() << endl << endl;
  sort(V.begin(), V.end());
  for (int i = 0; i < V.size(); i++) {
    cout << V[i] << endl;
  }
  return 0;
}
