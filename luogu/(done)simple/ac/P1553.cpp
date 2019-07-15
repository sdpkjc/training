#include <iostream>
#include <sstream>
using namespace std;

typedef long long ll;

ll f(string n) {
  string x(n.rbegin(), n.rend());
  stringstream ss;
  ss << x;
  ll re;
  ss >> re;
  if (re % 10ll == 0ll && re != 0) {
    re /= 10;
  }
  return re;
}

int main() {
  string s;
  cin >> s;
  if (s.find(".") == std::string::npos && s.find("/") == std::string::npos &&
      s.find("%") == std::string::npos) {
    cout << f(s);
  } else {
    if (s.find("%") != std::string::npos) {
      s = s.substr(0, s.length() - 1);
      cout << f(s) << "%";
    } else if (s.find("/") != std::string::npos) {
      string a = s.substr(0, s.find("/"));
      string b = s.substr(a.length() + 1, s.length() - a.length() - 1);
      cout << f(a) << "/" << f(b);
    } else if (s.find(".") != std::string::npos) {
      string a = s.substr(0, s.find("."));
      string b = s.substr(a.length() + 1, s.length() - a.length() - 1);

      cout << f(a) << "." << f(b);
    }
  }
}