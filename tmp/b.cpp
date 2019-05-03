#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
      int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    int ans = 0;
    for( int i = 1; i < a; i++){
        ans = max(ans,gcd(a^i,a&i));
    }
    cout << ans << endl;
  }
  return 0;
}