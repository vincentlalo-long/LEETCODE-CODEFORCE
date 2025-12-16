bool lemonadeChange(int* bills, int billsSize) {
    int money_slot[billsSize];
    int visited[1000];
    int cnt[1000]={0};
    for(int i=0;i<billsSize;i++){
        if(bills[i]==5){
            cnt[5]++;
        }
        else if(bills[i]==10){
            cnt[10]++;
            if(cnt[5]<=0) return false;
            cnt[5]--;
            
        }
        else{
            if(cnt[10]<=0 ){
                if(cnt[5]<=2) return false;
                else cnt[5]=cnt[5]-3;
            }
            else if(cnt[10]>=1 && cnt[5]<=0) return false;
            else {
                cnt[10]--;
                cnt[5]--;
            }
        }
    }
    return true;

}
