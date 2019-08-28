#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

bool ispr(int num) {
  if (num < 2) return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  if (ispr(N - 6) && ispr(N)) {
    cout << "Yes" << endl;
    cout << N - 6 << endl;
  } else if (ispr(N) && ispr(N + 6)) {
    cout << "Yes" << endl;
    cout << N + 6 << endl;
  } else {
    for (int i = N - 5;; i++) {
      if (ispr(i) && ispr(i + 6)) {
        cout << "No" << endl;
        if (i > N) {
          cout << i << endl;
        } else {
          cout << i + 6 << endl;
        }
        break;
      }
    }
  }

  return 0;
}