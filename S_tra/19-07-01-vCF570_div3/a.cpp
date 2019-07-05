#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool f(int num) {
  //   if (num % 4 != 0) return false;
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  if (sum % 4 != 0) return false;
  return true;
}

int main() {
  int n;
  cin >> n;

  int x = 0x3f3f3f3f;
  for (int i = n; i < 100000; i++) {
    if (f(i)) {
      x = i;
      break;
    }
  }
  cout << x << endl;
  return 0;
}