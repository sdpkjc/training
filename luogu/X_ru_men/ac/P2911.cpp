// P2911 [USACO08OCT]牛骨头Bovine Bones
// https://www.luogu.org/problem/P2911

#include <iostream>
using namespace std;

long long arr[200000];

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        arr[(i + j + k)]++;
      }
    }
  }
  long long maxx = -1;
  for (int i = 0; i <= a * b * c; i++) {
    maxx = max(maxx, arr[i]);
  }
  for (int i = 0; i <= a * b * c; i++) {
    if (maxx == arr[i]) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}