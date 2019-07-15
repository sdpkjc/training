#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int arr[200];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (s[i] - '0');
  }
  if (sum == n - sum) {
    cout << 2 << endl;
    cout << s.substr(0, 1) << " " << s.substr(1) << endl;
  } else {
    cout << 1 << endl;
    cout << s << endl;
  }
  return 0;
}