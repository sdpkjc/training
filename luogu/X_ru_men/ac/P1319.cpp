// P1319 压缩技术
// https://www.luogu.org/problem/P1319

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int arr[1000];
  int x, ii = 0;
  int n;
  cin >> n;
  while (cin >> x) {
    arr[ii++] = x;
  }
  int M[n * n];
  int cnt = 0;
  ii = 0;
  bool flag = true;
  for (int i = 0; i < n * n; i++) {
    while (cnt == 0) {
      cnt = arr[ii++];
      flag = !flag;
    }
    M[i] = flag;
    cnt--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i * n + j];
    }
    cout << endl;
  }

  return 0;
}