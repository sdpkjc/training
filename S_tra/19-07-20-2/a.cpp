#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define int long long
int arr[1000006];
signed main() {
  string str;
  cin >> str;
  str = " " + str;
  for (int i = 1; i < str.length(); i++) {
    arr[i] = arr[i - 1];
    if (str[i] == 'v' && str[i - 1] == 'v') {
      arr[i]++;
    }
  }
  int ans = 0;

  for (int i = 1; i < str.length(); i++) {
    if (str[i] == 'o') {
      int l = arr[i];
      int r = arr[str.length() - 1] - arr[i];
      //   cout << l << " " << r << endl;
      ans = ans + ((l) * (r));
    }
  }
  cout << ans << endl;
  return 0;
}
