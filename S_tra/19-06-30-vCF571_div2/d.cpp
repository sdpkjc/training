#include <cmath>
#include <iostream>
using namespace std;

double arr[100005];
int arrz[100005];
int flag[100005];
int main() {
  int n;
  cin >> n;
  int Bc = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arrz[i] = floor(arr[i]);
    if (abs(arr[i] - (int)arr[i]) < 1e-6) {
      flag[i] = 1;
    }
    Bc += arrz[i];
  }
  //   cout << Bc << endl;

  for (int i = 0; i < n; i++) {
    if (Bc == 0) {
      break;
    }
    if (flag[i] == 0) {
      Bc += 1;
      arrz[i] += 1;
    }
  }
  //   cout << Bc << endl;
  for (int i = 0; i < n; i++) {
    cout << arrz[i] << endl;
  }

  return 0;
}