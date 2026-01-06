#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    string t;
    cin>>s;
    cin>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    cout << (s.compare(t) ? "NO\n" : "YES\n");

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}