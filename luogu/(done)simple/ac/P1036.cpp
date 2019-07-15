#include <cmath>
#include <iostream>
using namespace std;

int arr[100];
int n, k;

bool ispr(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int ans;
void dfs(int sum, int kk, int ix) {
  if (kk == k) {
    if (ispr(sum)) ans++;
    return;
  }
  for (int i = ix; i < n; i++) {
    dfs(sum + arr[i], kk + 1, i + 1);
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ans = 0;
  dfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}