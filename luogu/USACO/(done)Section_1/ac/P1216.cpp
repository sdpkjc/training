// P1216 [IOI1994][USACO1.5]数字三角形 Number Triangles
// https://www.luogu.org/problemnew/show/P1216

#include <iostream>
using namespace std;

int arr[1005][1005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
      arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
    }
  }
  cout << arr[1][1] << endl;
  return 0;
}