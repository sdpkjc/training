#include <algorithm>
using namespace std;
const int MAXN = 105;
int dist[MAXN][MAXN];
void floyd(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
      }
    }
  }
}