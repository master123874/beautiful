#include<stdio.h>
#include<string.h>
#define N 100000
void change(int n,char b[],char ch)
{
    int i;
    if(n<=0)return;
    char t[N];
    if(strlen(b)>=n)
      for(i=strlen(b)-n;i<strlen(b);i++)printf("%c",b[i]);
    else 
    {
        for(i=0;i<n-strlen(b);i++)t[i]=ch;
        printf("%s",strcat(t,b));
    }
}
int main()
{
    int n;
    char ch;
    char B[N];
    scanf("%d ",&n);
    
    ch=getchar();
    getchar();
    gets(B);
    printf("%d",strlen(B));
    change(n,B,ch);
}
