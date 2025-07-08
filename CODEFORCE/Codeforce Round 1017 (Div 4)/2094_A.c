//LInk : https://codeforces.com/contest/2094/problem/A
// TRIPPI TROPPO
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char* solve(char* s){
    int len=strlen(s);
    char* res=malloc((len/2+2)*sizeof(char));
    s[strcspn(s, "\n")] = '\0';
    int index=0;
    res[index++]=s[0];
    for(int i=0;i<len;i++){
        if(s[i]==' '&&s[i+1]!='\0'&&s[i+1]!='\n'){
            res[index++]=s[i+1];
            
        }
    }
    res[index]='\0';
    return res;

}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
	    char s[1000];
	    fgets(s,sizeof(s),stdin);
	    char* res=solve(s);
	    printf("%s",res);
	    printf("\n");
	}
	

}

