#include <iostream>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int M[1005][1005];
int SUM[1005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    SUM[a]++;
    SUM[b]++;
    M[a][b]++;
    M[b][a]++;
  }
  int ansz = 0, ansm = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int z = M[i][j];
      int m = SUM[i] + SUM[j] - z;
      if (m != 0) {
        double x = (double)z / (double)m;
        double xx = (double)ansz / (double)ansm;
        if (x > xx) {
          ansz = z;
          ansm = m;
        }
      }
    }
  }
  int g = gcd(ansz, ansm);
  cout << ansz / g << "/" << ansm / g << endl;
  return 0;
}