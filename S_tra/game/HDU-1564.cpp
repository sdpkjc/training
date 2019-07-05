#include <iostream>
using namespace std;

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    if (n % 2 == 1) {
      cout << "ailyanlu";
    } else {
      cout << "8600";
    }
    cout << endl;
  }
  return 0;
}
