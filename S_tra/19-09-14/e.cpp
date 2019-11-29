#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 100005;

struct Edge {
  int v, cost;
  Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAX_N];
void addedge(int u, int v, int w) { E[u].push_back(Edge(v, w)); }

int A[MAX_N], B[MAX_N], C[MAX_N];

bool vis[MAX_N];
void dfs(int at, int L) {
  vis[at] = false;
  if (at != 0) {
    if (L % 3 == 0) {
      A[0] += (L * 2);
    } else if (L % 3 == 1) {
      B[0] += (L * 2);
    } else if (L % 3 == 2) {
      C[0] += (L * 2);
    }
  }
  for (int i = 0; i < E[at].size(); i++) {
    int v = E[at][i].v;
    int cost = E[at][i].cost;
    if (vis[v]) dfs(v, L + cost);
  }
}

void bfs() {
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
  }
}

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n - 1; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      addedge(a, b, c);
    }
    for (int i = 0; i < n; i++) {
      vis[i] = true;
    }
    dfs(0, 0);
    cout << A[0] << " " << B[0] << " " << C[0] << endl;
  }

  return 0;
}