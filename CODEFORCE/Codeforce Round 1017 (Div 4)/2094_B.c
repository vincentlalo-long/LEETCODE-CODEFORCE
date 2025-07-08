//Link : https://codeforces.com/contest/2094/problem/B

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void solve(){
    int n,m,l,r;
    scanf("%d %d %d %d",&n,&m,&l,&r);
    if(l>=0){
        printf("%d %d\n",0,m);
    }
    else{
        if(-m>l) printf("%d %d\n",-m,0);
        else{
            printf("%d %d\n",l,l+m);
        }
}
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}	



