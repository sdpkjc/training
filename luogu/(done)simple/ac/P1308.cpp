#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string g;
  cin >> g;
  for (int i = 0; i < g.length(); i++) {
    g[i] = tolower(g[i]);
  }
  int cnt = 0, in = -1;
  string t;
  getline(cin, t);
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    t[i] = tolower(t[i]);
  }
  string gg = " " + g + " ";
  t = " " + t + " ";

  stringstream ss;
  ss << t;
  in = t.find(gg);
  while (ss >> t) {
    if (g == t) {
      cnt++;
    }
  }
  if (cnt != 0) {
    cout << cnt << " " << in;
  } else {
    cout << -1;
  }
  cout << endl;
  return 0;
}