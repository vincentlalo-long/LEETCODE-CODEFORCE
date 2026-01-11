
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve(){
    int x , n;
    cin >>x>>n;
    if(n%2==1) {
        cout<<x<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}