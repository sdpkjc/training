// P1469 找筷子
// https://www.luogu.org/problem/P1469

#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> M;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    M[t]++;
  }
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
    if (it->second % 2 == 1) {
      cout << it->first << endl;
      break;
    }
  }

  return 0;
}