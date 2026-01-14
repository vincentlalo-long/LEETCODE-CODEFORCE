#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >> s;
        int len =s.length();
        s[len-1]='\0';
        s[len-2]='i';
        cout << s << "\n";

}
}