#include<stdio.h>
#include<string.h>
#define N 20
int main()
{
    char a[N];
    scanf("%s",a);
    int i;
    int t=0,count=strlen(a)-1;
    for(i=0;i<strlen(a);i++)
      if(a[i]=='2')t++;
    if(a[0]=='-'&&(a[count]-48)%2==0)printf("%.2f%%",(float)t/count*1.5*2*100);
    
}
