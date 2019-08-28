#include <string.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
string stra, strb;
map<string, int> M;

string A(string str) {
  string re(str.rbegin(), str.rend());
  return re;
}
string B(string str) {
  string re = str;
  for (int i = 0; i < 4; i++) {
    re[i] = str[(i - 1 + 4) % 4];
  }
  for (int i = 4; i < 8; i++) {
    re[i] = str[(i + 1 + 4) % 4 + 4];
  }
  return re;
}
string C(string str) {
  string re = str;
  re[1] = str[6];
  re[2] = str[1];
  re[5] = str[2];
  re[6] = str[5];
  return re;
}
string bfs() {
  queue<pair<string, string> > Q;
  Q.push(make_pair(stra, ""));
  M[stra] = 1;
  while (!Q.empty()) {
    string tmps = Q.front().first;
    string tmpa = Q.front().second;
    if (tmps == strb) {
      return tmpa;
    }
    Q.pop();
    string sa = A(tmps);
    string sb = B(tmps);
    string sc = C(tmps);
    if (M[sa] != 1) {
      Q.push(make_pair(sa, tmpa + "A"));
      M[sa] = 1;
    }
    if (M[sb] != 1) {
      Q.push(make_pair(sb, tmpa + "B"));
      M[sb] = 1;
    }
    if (M[sc] != 1) {
      Q.push(make_pair(sc, tmpa + "C"));
      M[sc] = 1;
    }
  }
  return "";
}

int main() {
  cin >> stra >> strb;
  cout << bfs() << endl;
  return 0;
}
