#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
    char s[N];
    scanf("%s",s);
    int sum=0;
    int i;
    for(i=0;i<strlen(s);i++)
       sum+=s[i]-48;
    int count=0;
    int a[10];
    int t=sum;
    while(sum>0)
    {
        a[count]=sum%10;
        count++;
        sum/=10;
        
    }
    for(i=count-1;i>=0;i--)
    {
        if(a[i]==0) printf("ling");
        else if(a[i]==1)printf("yi");
        else if(a[i]==2)printf("er");
        else if(a[i]==3)printf("san");
        else if(a[i]==4)printf("si");
        else if(a[i]==5)printf("wu");
        else if(a[i]==6)printf("liu");
        else if(a[i]==7)printf("qi");
        else if(a[i]==8)printf("ba");
        else if(a[i]==9)printf("jiu");
        if(i>0)printf(" ");  
    }
            
}
