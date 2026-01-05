// A . Submission Bait
//Link : https://codeforces.com/problemset/problem/1990/A

// code 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

bool checkWin(int n, vector<int> &a){
    if (n==0)   return false;
    if(n==1) return true;
    int max=a[n-1];
    int countMax=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]==max){
            countMax++;
        }
    }
    if(countMax%2==1){
        return true;
    }
    else{
        if(n-countMax>0) 
            return checkWin(n-countMax,a);
        else 
            return false;    
    }
    return false;
    
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int max=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        max=MAX(max,a[i]);
    }
    sort(a.begin(),a.end());
    cout <<((checkWin(n,a)) ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}