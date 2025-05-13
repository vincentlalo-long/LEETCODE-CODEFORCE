//Code C : 
int fib(int n){
    int dp_0=0;
    int dp_1=1;
    int dp_ans;
    if(n==0) return 0; // Simple case
    if(n==1) return 1; //Simple case
    for(int i=2;i<=n;i++){
        dp_ans=dp_0+dp_1; //Caculate Fib Numbers
        dp_0=dp_1;
        dp_1=dp_ans;
    }
    return dp_ans;
}
