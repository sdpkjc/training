#include <iostream>
#include <sstream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  if (n >= 0) {
    string sn;
    stringstream ss;
    ss << n;
    ss >> sn;
    string rsn(sn.rbegin(), sn.rend());
    stringstream rss;
    rss << rsn;
    rss >> n;
    cout << n << endl;
  } else {
    string sn;
    stringstream ss;
    ss << n;
    ss >> sn;
    sn = sn.substr(1);
    string rsn(sn.rbegin(), sn.rend());
    stringstream rss;
    rss << rsn;
    rss >> n;
    cout << "-" << n << endl;
  }

  return 0;
}