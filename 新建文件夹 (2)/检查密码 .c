#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 81
int judgeluan(char a[N])
{
    int i;
    for(i=0;i<strlen(a);i++)
       if(a[i]!='.'&&!isalpha(a[i])&&!isdigit(a[i]))return 1;
    return 0;   
}
int retucount1(char a[N])
{
    int i;
    int count=0;
    for(i=0;i<strlen(a);i++)
        if(isalpha(a[i]))return 1;
    return 0;    
}
int retucount(char a[N])
{
    int i;
    int count=0;
    for(i=0;i<strlen(a);i++)
        if(isdigit(a[i]))return 1;
    return 0;    
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    char a[N];
    getchar();
    for(i=0;i<n;i++)
    {
        gets(a);
        if(strlen(a)<6)
        {
            printf("Your password is tai duan le.\n");
        }
        else
        {
            if(judgeluan(a))printf("Your password is tai luan le.\n");
            else if(retucount1(a)&&retucount(a))printf("Your password is wan mei.\n");
            else if(retucount(a))printf("Your password needs zi mu.\n");
            else if(retucount1(a))printf("Your password needs shu zi.\n");
        }
    }
}
