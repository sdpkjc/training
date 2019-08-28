#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long double arr[100005];
long double one = 1.0;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%Lf", &arr[i]);
    }
    sort(arr, arr + n);
    long double gl = arr[0];
    long double mul = one - arr[0];
    for (int i = 1; i < n; i++) {
      long double tmp = gl * (one - arr[i]) + mul * arr[i];
      if (tmp <= gl) {
        // break;
      }
      mul = mul * (one - arr[i]);
      gl = tmp;
    }
    cout << gl << endl;
    // printf("%.10Lf\n", max(arr[n - 1], gl));
  }

  return 0;
}