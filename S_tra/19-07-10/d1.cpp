#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arrA[100005];
int arrB[100005];

int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "YES" << endl;
  } else {
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      arrA[a]++;
      arrB[b]++;
      arrA[b]++;
      arrB[a]++;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (arrA[i] == 2 && arrB[i] == 2) {
        flag = false;
      }
    }
    if (flag) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}