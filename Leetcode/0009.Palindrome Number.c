// https://leetcode.com/problems/palindrome-number/
bool isPalindrome(int x) {
    int stack[1000];
    int top=-1;
    int y=x;
    if(x<0) return false;
    while(x>0){
        stack[++top]=x%10;
        x=x/10;
    }
    x=y;
    while(x>0){
        if(x%10!=stack[top--]){
            return false;
        }
        x=x/10;
    }
    //if(found==1) return false;
    return true;
}
