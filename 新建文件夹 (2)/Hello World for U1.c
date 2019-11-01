#include<stdio.h>
#include<string.h>
#define N 90

int main(){
    char s[N];
    int i,j;
    while(scanf("%s",s)!=EOF){
        int side,mid,len;
        len=strlen(s);
        side=(len+2)/3;
        mid=len-side*2;
        for(i=0;i<side-1;i++){
            printf("%c",s[i]);
            for(j=0;j<mid;j++){
                printf(" ");
            }
            printf("%c\n",s[len-1-i]);
        }
        for(i=0;i<mid+2;i++){
            printf("%c",s[side-1+i]);
        }
        printf("\n");
    }
    return 0;
} 
