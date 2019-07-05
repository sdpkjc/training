#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
  string na;
  int num;
} arr[10000];

bool cmp(node &a, node &b) { return a.num > b.num; }

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i].na >> arr[i].num;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
      if (i != 0) cout << " ";
      cout << arr[i].na;
    }
    cout << endl;
  }

  return 0;
}