#include <iostream>
using namespace std;

int main() {
  cout << 100000 << endl;
  for (int j = 0; j < 1e5; j++) {
    for (int i = 0; i < 10; i++) {
      cout << "a";
    }
    cout << endl;
  }

  return 0;
}