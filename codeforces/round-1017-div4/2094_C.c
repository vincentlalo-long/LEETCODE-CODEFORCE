#include <stdio.h>
void solve(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    int res[2*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            res[i+j+2]=a[i][j];
        }
    }
    int sum=0;
    for(int i=2;i<=2*n;i++){
        sum+=res[i];
    }
    res[1]=(2*n)*(2*n+1)/2 -sum;
    for(int i=1;i<=2*n;i++){
        printf("%d ",res[i]);
        if(i==2*n) printf("\n");
    }
}
int main() {
	// your code goes here
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}

