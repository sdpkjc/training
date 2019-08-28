#include <iostream>
using namespace std;

int arr[1000005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        cnt += (j - i + 1) * (j - i) / 2;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}