#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector <int> count(4);
    for(int i = 0; i < n; i++){
        count[i % 4]++;
    }
    if (count[0]==count[3] && count[1]==count[2]){
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
}
}