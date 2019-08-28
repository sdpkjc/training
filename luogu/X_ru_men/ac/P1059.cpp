// P1059 明明的随机数
// https://www.luogu.org/problem/P1059

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int arr[1000];
int main() {
  int n;
  cin >> n;
  map<int, int> M;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    M[arr[i]]++;
  }
  sort(arr, arr + n);
  cout << M.size() << endl;
  cout << arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) cout << " " << arr[i];
  }
  cout << endl;
  return 0;
}