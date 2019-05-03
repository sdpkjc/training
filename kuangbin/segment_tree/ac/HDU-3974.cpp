// HDU-3974 Assign the task
// https://vjudge.net/problem/HDU-3974

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 50005;

int s[MAX_N];
struct edge {
  int u, next;
};
vector<edge> G[MAX_N];

int que(int x) { return s[x]; }

void update(int x, int sx) {
  s[x] = sx;
  for (int i = 0; i < G[x].size(); i++) {
    update(G[x][i].next, sx);
  }
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    memset(s, 0, sizeof(s));

    cout << "Case #" << t << ":" << endl;

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edge temp;
      temp.u = v;
      temp.next = u;
      G[v].push_back(temp);
    }
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
      char c;
      cin >> c;
      if (c == 'C') {
        int x;
        cin >> x;
        int num = que(x);
        if (num == 0) num -= 1;
        cout << num << endl;
      } else if (c == 'T') {
        int x, y;
        cin >> x >> y;
        update(x, y);
      }
    }
    for (int i = 0; i < MAX_N; i++) G[i].clear();
  }
  return 0;
}

// 模拟水过