#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int arr[200005];
int main() {
  map<int, int> M;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    M[arr[i]]++;
  }

  for (int i = 0; i < n; i++) {
    M[arr[i]]--;
    map<int, int>::iterator it = --M.end();
    while (it->second == 0) {
      it--;
    }
    cout << it->first << endl;
    M[arr[i]]++;
  }

  return 0;
}