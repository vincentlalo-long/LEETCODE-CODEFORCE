#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    vector<int> a(4);
    for(int i=0;i<4;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0]==a[1] && a[0]==a[2] && a[0]==a[3]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t;
    while(t--){
        solve();
}
}

