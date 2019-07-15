#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arr[100005];
int sums[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sums[i] = sums[i - 1] + arr[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int sum = sums[b] - sums[a - 1];
    cout << sum / 10 << endl;
  }
  return 0;
}