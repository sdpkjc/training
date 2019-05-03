// A - B <= D -> add(A，B，D)
// A - B >= D -> 同乘 - 1得 B - A <= -D -> add(B，A，-D)

#include <string.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10005;

int M, N, D;

struct edge {
  long long next, weight;
};
vector<edge> G[MAX_N];

// long long degree[MAX_N];
// long long money[MAX_N];

bool inq[MAX_N];
long long dist[MAX_N];
long long cnt[MAX_N];

bool spfa(int s) {
  memset(inq, false, sizeof(inq));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < MAX_N; i++) {
    dist[i] = 2147483647;
  }

  dist[s] = 0;
  inq[s] = true;

  queue<int> que;

  que.push(s);
  cnt[s]++;

  while (!que.empty()) {
    int u = que.front();
    que.pop();

    inq[u] = false;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i].next;
      if (dist[u] + G[u][i].weight < dist[v]) {
        dist[v] = dist[u] + G[u][i].weight;
        if (!inq[v]) {
          que.push(v);
          inq[v] = true;
          cnt[v]++;
          if (cnt[v] > N + 1) return false;
        }
      }
    }
  }
  return true;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    int a, b, w;
    edge ex;
    if (x == 1) {
      // a-b >= w
      cin >> a >> b >> w;
      ex.next = b;
      ex.weight = -w;
      G[a].push_back(ex);
    } else if (x == 2) {
      // a-b <= w
      cin >> a >> b >> w;
      ex.next = a;
      ex.weight = w;
      G[b].push_back(ex);
    } else if (x == 3) {
      cin >> a >> b;
      ex.weight = 0;
      ex.next = a;
      G[b].push_back(ex);
      ex.next = b;
      G[a].push_back(ex);
    }
  }
  for (int i = 1; i <= N; i++) {
    edge ex;
    ex.weight = 0;
    ex.next = i;
    G[N + 1].push_back(ex);
    // ex.next = b;
    // G[a].push_back(ex);
  }
  if (spfa(N + 1)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
}

