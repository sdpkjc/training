#include <iostream>
#include <vector>
using namespace std;

int arr[200005], arrF[200005];
vector<int> va;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  bool f1 = true;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      bool f = false;
      for (int j = 1; i * j <= n; j++) {
        if (arrF[j * i] != 1) {
          arrF[j * i] = 1;
          f = true;
          break;
        }
      }
      f1 = f1 && f;
      if (!f1) break;
    }
  }
  if (f1) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += arrF[i];
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
      if (arrF[i]) cout << i << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
