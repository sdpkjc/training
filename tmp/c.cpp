#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int tp[100];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
  tp[0] = 1;
  for (int i = 1; i < 30; i++) {
    tp[i] = tp[i - 1] * 2;
  }
  int n = 26;
  cout << "[";
  for (int i = 0; i < 26; i++) {
    int tmp;
    cin >> tmp;
    cout << tmp << ", ";
  }
  cout << "]" << endl;

  return 0;
}