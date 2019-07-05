// P1201 [USACO1.1]贪婪的送礼者Greedy Gift Givers
// https://www.luogu.org/problemnew/show/P1201

#include <iostream>
#include <map>
using namespace std;

map<string, int> M;
string arrs[200];
int arr[200];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    M[str] = i;
    arrs[i] = str;
  }
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    int na = M[name];
    int a, b;
    cin >> a >> b;
    int q = 0;
    if (b != 0) {
      q = a / b;
    }
    // arr[na] += (a);
    arr[na] -= (q * b);
    for (int j = 0; j < b; j++) {
      string tmp;
      cin >> tmp;
      arr[M[tmp]] += q;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arrs[i] << " " << arr[i] << endl;
  }
  return 0;
}