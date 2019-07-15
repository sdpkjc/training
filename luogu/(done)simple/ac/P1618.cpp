#include <iostream>
using namespace std;

bool jc(int A, int B, int C) {
  if (A < 100 || A >= 1000) return false;
  if (B < 100 || B >= 1000) return false;
  if (C < 100 || C >= 1000) return false;

  int arr[20] = {0};
  while (A != 0) {
    arr[A % 10]++;
    A /= 10;
  }

  while (B != 0) {
    arr[B % 10]++;
    B /= 10;
  }

  while (C != 0) {
    arr[C % 10]++;
    C /= 10;
  }

  for (int i = 1; i < 10; i++) {
    if (arr[i] != 1) return false;
  }
  if (arr[0] != 0) return false;
  return true;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < 10000; i++) {
    if (jc(i * a, i * b, i * c)) {
      cout << i * a << " " << i * b << " " << i * c << endl;
      ans++;
    }
  }
  if (ans == 0) {
    cout << "No!!!" << endl;
  }
  return 0;
}