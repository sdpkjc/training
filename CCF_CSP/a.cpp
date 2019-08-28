#include <cmath>
#include <iostream>
using namespace std;

int arr[100005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  double c = 0;
  if (n % 2 == 1) {
    c = arr[n / 2];
  } else {
    c = (double)(arr[n / 2] + arr[n / 2 - 1]) / 2.0;
  }
  if (arr[0] > arr[n - 1]) {
    if (abs(c - (int)c) < 1e-5) {
      printf("%d %.0lf %d\n", arr[0], c, arr[n - 1]);
    } else {
      printf("%d %.1lf %d\n", arr[0], c, arr[n - 1]);
    }
  } else {
    if (abs(c - (int)c) < 1e-5) {
      printf("%d %.0lf %d\n", arr[n - 1], c, arr[0]);
    } else {
      printf("%d %.1lf %d\n", arr[n - 1], c, arr[0]);
    }
  }
  return 0;
}