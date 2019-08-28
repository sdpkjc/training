#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_N = 350005;
int arr[MAX_N];
int flag[MAX_N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = n - 1; i >= 0; i--) {
    if (flag[arr[i] + 1] != 1) {
      flag[arr[i] + 1] = 1;
    } else if (flag[arr[i]] != 1) {
      flag[arr[i]] = 1;
    } else if (flag[arr[i] - 1] != 1) {
      flag[arr[i] - 1] = 1;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= 150004; i++) {
    if (flag[i]) {
      cnt++;
    }
  }
  cout << cnt << endl;
}