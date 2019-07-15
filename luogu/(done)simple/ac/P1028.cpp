#include <string.h>
#include <iostream>
using namespace std;

int x[2000];

int main() {
  for (int i = 1; i <= 1000; i++) {
    x[i] = 1;
    for (int j = 1; j <= i / 2; j++) {
      x[i] += x[j];
    }
  }
  int n;
  cin >> n;
  cout << x[n] << endl;
  return 0;
}