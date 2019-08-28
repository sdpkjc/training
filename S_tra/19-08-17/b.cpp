#include <iostream>
#include <map>
#include <queue>
using namespace std;

unsigned long long sign(unsigned long long n) {
  if (n == 1ull || n == 3ull || n == 0ull) {
    return 0;
  }
  int cnt = 0;
  if (n > 0ull) {
    cnt++;
  }
  if (n > 1ull) {
    cnt++;
  }
  if (n > 3ull) {
    cnt++;
  }
  if (cnt % 2 == 0) {
    return -1;
  }
  return 1;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    unsigned long long n;
    cin >> n;
    unsigned long long x = 1ull - 6ull * n + 14ull * n * n + 4ull * sign(n);
    cout << x << endl;
  }

  return 0;
}