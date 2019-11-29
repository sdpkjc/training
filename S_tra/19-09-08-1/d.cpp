#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[100000];
int n, m, q;
bool f() {
  for (int i = 0; i < n; i++) {
    if (arr[i] != i + 1) return false;
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
      arr[i] = i + 1;
    }
    int cnt = 0;
    do {
      cnt++;
      queue<int> Q;
      for (int i = 0; i < n; i++) {
        Q.push(arr[i]);
      }
      int ind = 0;
      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        arr[ind++] = x;
        for (int i = 0; i < m; i++) {
          int y = Q.front();
          Q.pop();
          Q.push(y);
        }
      }
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }

      cout << endl;
    } while (!f());
    cout << cnt << endl;
  }
  return 0;
}
// 1 2 3 4 5
// 1 3 5 4 2
// 1 5 2 4 3