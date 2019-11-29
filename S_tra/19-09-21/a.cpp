#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    int cnt = 1;
    while(T--){
        int n;
        cin >> n;
        cout << "Case "<<cnt << ": ";
        int cc;
        for( cc = 1; ; cc++){
            if(cc*cc + 2*cc >= n)break;
        }
        if(cc % 2 == 1){
            cout <<  "odd";
        }else{
            cout << "even";
        }
        cout << endl;
        cnt++;
    }
    return 0;
}