#pragma comment(linker, "/STACK:102400000000,102400000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool isp(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

const int MAX_N = 1e9 + 7;

// vector<int> V;
bool flag[MAX_N + 1];
int arr[(int)1e5];

int eratosthenes(int N) {
  memset(flag, true, (N + 1) * sizeof(bool));
  for (int p = 2; p * p <= N; p++) {
    if (flag[p]) {
      for (int x = p * p; x <= N; x += p) {
        flag[x] = false;
      }
    }
  }
  int nPrimes = 0;
  for (int i = 2; i <= N; i++) {
    if (flag[i]) {
      arr[i / (int)1e5]++;
    }
  }
  return nPrimes;
}

int main() {
  eratosthenes(1e9);

  for (int i = 0; i <= 1e4; i++) {
    cout << arr[i] << ",";
  }
  return 0;
}
