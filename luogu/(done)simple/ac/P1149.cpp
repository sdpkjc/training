#include <iostream>
using namespace std;

int arr[100] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int ca(int n) {
  if (n == 0) return arr[0];
  int re = 0;
  while (n != 0) {
    re += arr[n % 10];
    n /= 10;
  }
  return re;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = i; j < 1000; j++) {
      int cnt = 4 + ca(i) + ca(j) + ca(i + j);
      if (cnt == n) {
        ans++;
        if (i != j) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}