#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arr[200];
int main() {
  for (int i = 0; i < 120; i++) {
    arr[i] = 4 * i;
  }

  int n;
  cin >> n;
  int ans = 1;
  for (int i = 1; i < n; i++) {
    ans += arr[i];
  }

  cout << ans << endl;
  return 0;
}