#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int q, k;
    cin >> q >> k;
    while (q--) {
      int a, b;
      cin >> a >> b;
      int z1 = (a - 1 + b - 1) % 2;
      int z2 = ((min(a, b) - 1) / k) % 2;
      int z3 = ((min(a, b) - 2) / k) % 2;
      int z4 = ((min(a, b) - 3) / k) % 2;
      // cout<<z1<<" "<<z2<<" "<<z3<<" "<<z4<<endl;
      if (min(a, b) < k + 1) {
        if (z1 == 1)
          cout << "Alice" << endl;
        else
          cout << "Bob" << endl;
      } else if (z1 + z2 + z3 == 3 || z1 + z2 + z3 == 0)
        cout << "Bob" << endl;
      else if (z3 == 1 && z4 == 0) {
        if (z1 == 1 && z2 == 1) cout << "Bob" << endl;
        if (z1 == 1 && z2 == 0) cout << "Alice" << endl;
        if (z1 == 0 && z2 == 0) cout << "Bob" << endl;
        if (z1 == 0 && z2 == 1) cout << "Alice" << endl;
      } else
        cout << "Alice" << endl;
    }
  }
}