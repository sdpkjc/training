#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> V;

int main() {
  V.push_back(1);
  V.push_back(3);
  V.push_back(5);
  V.push_back(10);

  auto it = lower_bound(V.begin(), V.end(), 10);
  vector<int> tmp;
  //   cout << max(it - V.begin(), 0l) << endl;
  //   cout << min(it + 2 - V.begin(), V.end() - V.begin()) << endl;

  for (int i = max(it - V.begin() - 2, 0l);
       i < min(it + 2 - V.begin(), V.end() - V.begin()); i++) {
    cout << V[i] << endl;
  }
  V.insert(it, 1);

  //   cout << (it - V.begin()) << endl;
  return 0;
}
