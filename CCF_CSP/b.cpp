#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int ia[4] = {s[0] - '0', s[2] - '0', s[4] - '0', s[6] - '0'};
    char ca[3] = {s[1], s[3], s[5]};
    stack<int> INT;
    stack<int> CHAR;
    INT.push(ia[0]);
    vector<char> cv;
    vector<int> iv;

    for (int i = 0; i < 3; i++) {
      if (ca[i] == '+' || ca[i] == '-') {
        INT.push(ia[i + 1]);
        CHAR.push(ca[i]);
        cv.push_back(ca[i]);
      } else {
        int x = INT.top();
        INT.pop();
        if (ca[i] == 'x') {
          INT.push(ia[i + 1] * x);
        } else {
          INT.push(x / ia[i + 1]);
        }
      }
    }
    while (INT.size() != 0) {
      iv.push_back(INT.top());
      INT.pop();
    }
    iv = vector<int>(iv.rbegin(), iv.rend());
    int sum = iv[0];
    for (int i = 0; i < cv.size(); i++) {
      if (cv[i] == '+') {
        sum += iv[i + 1];
      } else {
        sum -= iv[i + 1];
      }
    }
    if (sum == 24) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}