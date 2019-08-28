// P4414 [COCI2006-2007#2] ABC
// https://www.luogu.org/problem/P4414

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr, arr + 3);
  int ans[3];
  string s;
  cin >> s;
  for (int i = 0; i < 3; i++) {
    ans[i] = arr[s[i] - 'A'];
  }
  for (int i = 0; i < 3; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}