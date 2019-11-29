#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  if (n % 2ll == 0ll) {
    cout << (n / 2ll) * (n / 2ll) << endl;
  } else {
    cout << (n / 2ll) * (n / 2ll + 1ll) << endl;
  }
  return 0;
}