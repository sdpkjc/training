#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    sum += abs(t - p);
  }
  cout << sum << endl;
  return 0;
}