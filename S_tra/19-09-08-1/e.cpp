#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[100000];
int n, m, q;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
      arr[i] = i + 1;
    }
    int cnt = 0;

    deque<int> Q;
    for (int i = 0; i < n; i++) {
      Q.push_front(arr[i]);
    }
    int ind = 0;
    while (!Q.empty()) {
      int x = Q.back();
      Q.pop_back();
      arr[ind++] = x;
      for (int i = 0; i < n - m - 1; i++) {
        int y = Q.back();
        Q.pop_back();
        Q.push_front(y);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }

    cout << endl;
  }
  return 0;
}
// 1 2 3 4 5
// 1 3 5 4 2
// 1 5 2 4 3