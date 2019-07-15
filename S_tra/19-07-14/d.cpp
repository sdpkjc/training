#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int X, K, A[100];
bool win[1000 + 1];
void solve() {
  win[0] = false;

  for (int j = 1; j <= X; j++) {
    win[j] = false;
    for (int i = 0; i < K; i++) {
      win[j] |= A[i] <= j && !win[j - A[i]];
    }
  }
  if (win[X])
    cout << "Alice";
  else
    cout << "Bob";
  cout << endl;
}
int main() {
  int T;
  cin >> T;

  while (T--) {
    cin >> X >> A[2];
    K = 3;
    A[0] = 1;
    A[1] = 2;
    // cout << A[2] << ": ";
    solve();
    for (int i = 0; i <= X; i++) {
      // cout << i << ": " << win[i] << endl;
    }
  }

  return 0;
}
