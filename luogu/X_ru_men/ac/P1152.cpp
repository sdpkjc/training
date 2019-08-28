// P1152 欢乐的跳
// https://www.luogu.org/problem/P1152

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int arr[1005];
map<int, int> M;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  for (int i = 1; i < n; i++) {
    int x = abs(arr[i] - arr[i - 1]);
    if (x >= 1 && x <= n - 1) M[x]++;
  }
  if (M.size() == n - 1)
    cout << "Jolly";
  else
    cout << "Not jolly";
  cout << endl;
  return 0;
}