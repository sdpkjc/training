#include <iostream>
#include <set>
using namespace std;

#define int long long

bool f(int n) {
  int x = n / 3ll * 3ll;
  int xx = (n / 3ll - 1) * 3ll;

  bool flag = false;
  if (x == n) {
    flag = true;
  } else {
    if (((3 | x) == n || (xx | x) == n)) {
      flag = true;
    }
  }
  if (!flag) {
    cout << n << endl;
  }
  return flag;
}

signed main() {
  int arr[10] = {3, 6, 9, 12, 15, 18, 21};

  set<int> S;
  do {
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    S.insert(a | b);
    S.insert(a | c);
    S.insert(b | c);
    S.insert(a | b | c);
    int x = f(a | b);
    if (!x) {
      cout << a << " " << b << endl;
    }
    x = f(b | c);
    if (!x) {
      cout << b << " " << c << endl;
    }

    x = f(a | c);
    if (!x) {
      cout << a << " " << c << endl;
    }
    x = f(a | b | c);
    if (!x) {
      cout << a << " " << b << " " << c << endl;
    }
  } while (next_permutation(arr, arr + 7));

  // 1276
  cout << (1266 | 1269) << " " << (1272 | 6) << " " << (1272 | 9);
}