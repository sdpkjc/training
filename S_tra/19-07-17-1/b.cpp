#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arr[100005];
vector<int> fv, zv;
int main() {
  int n;
  cin >> n;
  int fs = 0, zs = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] >= 0) arr[i] = -arr[i] - 1;
  }
  if (n % 2 == 1) {
    int maxx = 1e6 + 10;
    int x = -1;
    for (int i = 0; i < n; i++) {
      if (maxx > arr[i]) {
        maxx = arr[i];
        x = i;
      }
    }
    arr[x] = -arr[x] - 1;
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << arr[i];
  }
  cout << endl;
  return 0;
}