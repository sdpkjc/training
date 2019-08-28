#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int x = n / 3ll * 3ll;
    if (x == n) {
      cout << 1 << " " << x << endl;
    } else {
      vector<int> V;
      for (int i = 0; i < 5; i++) {
        int y = (n / 3ll - i) * 3ll;
        if (y > 0) V.push_back(y);
      }
      vector<int> VV;
      VV.push_back(3);
      VV.push_back(6);
      VV.push_back(9);
      VV.push_back(12);
      VV.push_back(15);
      bool flag = true;
      for (int i = 0; i < V.size() && flag; i++) {
        for (int j = 0; j < VV.size() && flag; j++) {
          int a = V[i];
          int b = VV[j];
          if ((a | b) == n) {
            cout << 2 << " " << a << " " << b << endl;
            flag = false;
          }
        }
      }
      for (int i = 0; i < V.size() && flag; i++) {
        for (int j = i + 1; j < V.size() && flag; j++) {
          int a = V[i];
          int b = V[j];
          if ((a | b) == n) {
            cout << 2 << " " << a << " " << b << endl;
            flag = false;
          }
        }
      }

      for (int i = 0; i < VV.size() && flag; i++) {
        for (int j = i + 1; j < VV.size() && flag; j++) {
          int a = VV[i];
          int b = VV[j];
          if ((a | b) == n) {
            cout << 2 << " " << a << " " << b << endl;
            flag = false;
          }
        }
      }
    }
  }
}