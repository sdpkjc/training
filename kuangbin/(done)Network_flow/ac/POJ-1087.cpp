// POJ-1087 A Plug for UNIX
// https://vjudge.net/problem/POJ-1087

#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 2010;     //点数的最大值
const int MAXM = 1200010;  //边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, next, cap, flow;
} edge[MAXM];  //注意是 MAXM
int tol;
int head[MAXN];
void init() {
  tol = 2;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0) {
  edge[tol].to = v;
  edge[tol].cap = w;
  edge[tol].flow = 0;

  edge[tol].next = head[u];
  head[u] = tol++;

  edge[tol].to = u;
  edge[tol].cap = rw;
  edge[tol].flow = 0;

  edge[tol].next = head[v];
  head[v] = tol++;
}
int Q[MAXN];
int dep[MAXN], cur[MAXN], sta[MAXN];
bool bfs(int s, int t, int n) {
  int front = 0, tail = 0;
  memset(dep, -1, sizeof(dep[0]) * (n + 1));
  dep[s] = 0;
  Q[tail++] = s;

  while (front < tail) {
    int u = Q[front++];
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap > edge[i].flow && dep[v] == -1) {
        dep[v] = dep[u] + 1;
        if (v == t) return true;
        Q[tail++] = v;
      }
    }
  }
  return false;
}
int dinic(int s, int t, int n) {
  int maxflow = 0;
  while (bfs(s, t, n)) {
    for (int i = 0; i < n; i++) cur[i] = head[i];
    int u = s, tail = 0;
    while (cur[s] != -1) {
      if (u == t) {
        int tp = INF;
        for (int i = tail - 1; i >= 0; i--)
          tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
        maxflow += tp;
        for (int i = tail - 1; i >= 0; i--) {
          edge[sta[i]].flow += tp;
          edge[sta[i] ^ 1].flow -= tp;
          if (edge[sta[i]].cap - edge[sta[i]].flow == 0) tail = i;
        }
        u = edge[sta[tail] ^ 1].to;
      } else if (cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow &&
                 dep[u] + 1 == dep[edge[cur[u]].to]) {
        sta[tail++] = cur[u];
        u = edge[cur[u]].to;
      } else {
        while (u != s && cur[u] == -1) u = edge[sta[--tail] ^ 1].to;
        cur[u] = edge[cur[u]].next;
      }
    }
  }
  return maxflow;
}

int main() {
  init();
  map<string, int> dex;    //插头编号
  map<string, int> dqdex;  //电器编号
  vector<int> ctA;
  vector<int> ctB;

  int S = 0, T = 600;

  int n;
  cin >> n;
  int cnt = 1;
  int arr[200] = {0};
  for (int i = 1; i <= n; i++) {
    string tmp;
    cin >> tmp;
    if (dex.find(tmp) == dex.end()) {
      dex[tmp] = cnt++;
    }
    arr[dex[tmp]]++;
  }
  for (map<string, int>::iterator it = dex.begin(); it != dex.end(); it++) {
    int tt = it->second;
    addedge(tt, T, arr[tt]);
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    string a, b;
    cin >> a >> b;
    if (dqdex.find(a) == dqdex.end()) {
      dqdex[a] = cnt++;
    }
    if (dex.find(b) == dex.end()) {
      dex[b] = cnt++;
    }
    addedge(S, dqdex[a], 1);
    addedge(dqdex[a], dex[b], 1);
  }
  int q;
  cin >> q;
  int chdex = cnt;
  for (int i = 0; i < q; i++) {
    string a, b;
    cin >> a >> b;
    if (dex.find(a) == dex.end()) {
      dex[a] = cnt++;
    }
    if (dex.find(b) == dex.end()) {
      dex[b] = cnt++;
    }
    ctA.push_back(dex[a]);
    ctB.push_back(dex[b]);
  }

  for (int i = 0; i < ctA.size(); i++) {
    addedge(ctA[i], ctB[i], INF);
  }

  int ans = dinic(S, T, T + 10);
  cout << m - ans << endl;
  return 0;
}

// 没读懂题。。。
// 无限个转换器，插座可能同一种有多个，转换器只能把前一个转换成后一个（有题解胡说八道）
// 基本是裸最大流，转换器就是从 A 向 B 引一条边