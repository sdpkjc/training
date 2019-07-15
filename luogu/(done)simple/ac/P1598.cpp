#include <iostream>
using namespace std;
int arr[30000];

int main() {
  string t;
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    if (t[i] >= 'A' && t[i] <= 'Z') arr[t[i] - 'A']++;
  }
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    if (t[i] >= 'A' && t[i] <= 'Z') arr[t[i] - 'A']++;
  }
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    if (t[i] >= 'A' && t[i] <= 'Z') arr[t[i] - 'A']++;
  }
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    if (t[i] >= 'A' && t[i] <= 'Z') arr[t[i] - 'A']++;
  }
  int maxc = 0;
  for (int i = 0; i < 26; i++) {
    if (maxc < arr[i]) {
      maxc = arr[i];
    }
  }

  for (int i = maxc; i > 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (j != 0) cout << " ";
      if (arr[j] >= i) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
  return 0;
}