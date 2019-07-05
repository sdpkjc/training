#include <iostream>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  if (n <= m && n <= k) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
  return 0;
}